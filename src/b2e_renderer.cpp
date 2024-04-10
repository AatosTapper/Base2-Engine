#include "b2e_renderer.h"
#include "VK_CHECK.h"

#include <array>
#include <iostream>

namespace b2e
{
    B2eRenderer::B2eRenderer(B2eWindow &window, B2eDevice &device) :
        m_b2e_window(window), m_b2e_device(device)
    {
        m_recreate_swap_chain();
        m_create_command_buffers();
    }

    B2eRenderer::~B2eRenderer()
    {
        m_free_command_buffers();
    }

    void B2eRenderer::m_recreate_swap_chain()
    {
        auto extent = m_b2e_window.get_extent();
        while (extent.width == 0 || extent.height == 0)
        {
            extent = m_b2e_window.get_extent();
            glfwWaitEvents();
        }

        vkDeviceWaitIdle(m_b2e_device.device());

        if (m_b2e_swap_chain == nullptr)
        {
            m_b2e_swap_chain = std::make_unique<B2eSwapChain>(m_b2e_device, extent);
        }
        else
        {
            m_b2e_swap_chain = std::make_unique<B2eSwapChain>(m_b2e_device, extent, std::move(m_b2e_swap_chain));
            if (m_b2e_swap_chain->image_count() != m_command_buffers.size())
            {
                m_free_command_buffers();
                m_create_command_buffers();
            }
        }

        // HERE
    }

    void B2eRenderer::m_create_command_buffers()
    {
        m_command_buffers.resize(m_b2e_swap_chain->image_count());

        VkCommandBufferAllocateInfo alloc_info = {};
        alloc_info.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
        alloc_info.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
        alloc_info.commandPool = m_b2e_device.get_command_pool();
        alloc_info.commandBufferCount = static_cast<uint32_t>(m_command_buffers.size());

        VK_CHECK(vkAllocateCommandBuffers(m_b2e_device.device(), &alloc_info, m_command_buffers.data()));
    }

    void B2eRenderer::m_free_command_buffers()
    {
        vkFreeCommandBuffers(
            m_b2e_device.device(), 
            m_b2e_device.get_command_pool(), 
            static_cast<uint32_t>(m_command_buffers.size()), 
            m_command_buffers.data()
        );
        m_command_buffers.clear();
    }
    
    VkCommandBuffer B2eRenderer::begin_frame()
    {
        assert(!m_is_frame_started && "Cannot call begin_frame with a frame already in progress");

        auto result = m_b2e_swap_chain->acquire_next_image(&m_current_image_index);

        if (result == VK_ERROR_OUT_OF_DATE_KHR)
        {
            m_recreate_swap_chain();
            return nullptr;
        }

        if (result != VK_SUCCESS && result != VK_SUBOPTIMAL_KHR)
        {
            throw std::runtime_error("Failed to acquire swap chain");
        }

        m_is_frame_started = true;

        auto command_buffer = get_current_command_buffer();

        VkCommandBufferBeginInfo begin_info = {};
        begin_info.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;

        VK_CHECK(vkBeginCommandBuffer(command_buffer, &begin_info));
        return command_buffer;
    }

    void B2eRenderer::end_frame()
    {
        assert(m_is_frame_started && "Cannot call end_frame without a frame in progress");
        auto command_buffer = get_current_command_buffer();

        VK_CHECK(vkEndCommandBuffer(command_buffer));

        auto result = m_b2e_swap_chain->submit_command_buffers(&command_buffer, &m_current_image_index);
        if (result == VK_ERROR_OUT_OF_DATE_KHR || result == VK_SUBOPTIMAL_KHR || m_b2e_window.was_window_resized())
        {
            m_b2e_window.reset_window_resized_flag();
            m_recreate_swap_chain();
        }
        VK_CHECK(result);

        m_is_frame_started = false;
    }

    void B2eRenderer::begin_swap_chain_render_pass(VkCommandBuffer command_buffer)
    {
        assert(m_is_frame_started && "Cannot call begin_swap_chain_render_pass without a frame in progress");
        assert(command_buffer == get_current_command_buffer() && "Cannot begin render pass on command buffer from a different frame");

        VkRenderPassBeginInfo render_pass_info = {};
        render_pass_info.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
        render_pass_info.renderPass = m_b2e_swap_chain->get_render_pass();
        render_pass_info.framebuffer = m_b2e_swap_chain->get_frame_Buffer(m_current_image_index);

        render_pass_info.renderArea.offset = { 0, 0 };
        render_pass_info.renderArea.extent = m_b2e_swap_chain->get_swap_chain_extent();

        std::array<VkClearValue, 2> clear_values = {};
        clear_values[0].color = {{ 0.0f, 0.0f, 0.0f, 0.0f }};
        clear_values[1].depthStencil = { 1.0f, 0u };
        render_pass_info.clearValueCount = static_cast<uint32_t>(clear_values.size());
        render_pass_info.pClearValues = clear_values.data();

        vkCmdBeginRenderPass(command_buffer, &render_pass_info, VK_SUBPASS_CONTENTS_INLINE);

        VkViewport viewport = {};
        viewport.x = 0.0f;
        viewport.y = 0.0f;
        viewport.width = static_cast<float>(m_b2e_swap_chain->get_swap_chain_extent().width);
        viewport.height = static_cast<float>(m_b2e_swap_chain->get_swap_chain_extent().height);
        viewport.minDepth = 0.0f;
        viewport.maxDepth = 1.0f;
        VkRect2D scissor = {{ 0, 0 }, m_b2e_swap_chain->get_swap_chain_extent()};
        vkCmdSetViewport(command_buffer, 0, 1, &viewport);
        vkCmdSetScissor(command_buffer, 0, 1, &scissor);
    }

    void B2eRenderer::end_swap_chain_render_pass(VkCommandBuffer command_buffer)
    {
        assert(m_is_frame_started && "Cannot call end_swap_chain_render_pass without a frame in progress");
        assert(command_buffer == get_current_command_buffer() && "Cannot end render pass on command buffer from a different frame");

        vkCmdEndRenderPass(command_buffer);
    }
}