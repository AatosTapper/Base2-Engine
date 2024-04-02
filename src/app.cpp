#include "app.h"
#include "VK_CHECK.h"

#include <array>

namespace b2e
{
    App::App()
    {
        m_create_pipeline_layout();
        m_create_pipeline();
        m_create_command_buffers();
    }

    App::~App()
    {
        vkDestroyPipelineLayout(m_b2e_device.device(), m_pipeline_layout, nullptr);
    }

    void App::run()
    {
        while (!m_b2e_window.should_close())
        {
            glfwPollEvents();
            m_draw_frame();
        }

        vkDeviceWaitIdle(m_b2e_device.device());
    }

    void App::m_create_pipeline_layout()
    {
        VkPipelineLayoutCreateInfo pipeline_layout_info = {};
        pipeline_layout_info.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
        pipeline_layout_info.setLayoutCount = 0;
        pipeline_layout_info.pSetLayouts = nullptr;
        pipeline_layout_info.pushConstantRangeCount = 0;
        pipeline_layout_info. pPushConstantRanges = nullptr;

        VK_CHECK(vkCreatePipelineLayout(m_b2e_device.device(), &pipeline_layout_info, nullptr, &m_pipeline_layout));
    }

    void App::m_create_pipeline()
    {
        auto pipeline_config = B2ePipeline::default_pipeline_config_info(m_b2e_swap_chain.width(), m_b2e_swap_chain.height());
        pipeline_config.render_pass = m_b2e_swap_chain.get_render_pass();
        pipeline_config.pipeline_layout = m_pipeline_layout;
        m_b2e_pipeline = std::make_unique<B2ePipeline>(m_b2e_device,
            "../shaders/SPIRV/default.vert.spv", 
            "../shaders/SPIRV/default.frag.spv",
            pipeline_config
        );
    }

    void App::m_create_command_buffers()
    {
        m_command_buffers.resize(m_b2e_swap_chain.image_count());

        VkCommandBufferAllocateInfo alloc_info = {};
        alloc_info.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
        alloc_info.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
        alloc_info.commandPool = m_b2e_device.get_command_pool();
        alloc_info.commandBufferCount = static_cast<uint32_t>(m_command_buffers.size());

        VK_CHECK(vkAllocateCommandBuffers(m_b2e_device.device(), &alloc_info, m_command_buffers.data()));

        for (uint32_t i = 0; i < m_command_buffers.size(); i++)
        {
            VkCommandBufferBeginInfo begin_info = {};
            begin_info.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;

            VK_CHECK(vkBeginCommandBuffer(m_command_buffers[i], &begin_info));

            VkRenderPassBeginInfo render_pass_info = {};
            render_pass_info.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
            render_pass_info.renderPass = m_b2e_swap_chain.get_render_pass();
            render_pass_info.framebuffer = m_b2e_swap_chain.get_frame_Buffer(i);

            render_pass_info.renderArea.offset = { 0, 0 };
            render_pass_info.renderArea.extent = m_b2e_swap_chain.get_swap_chain_extent();

            std::array<VkClearValue, 2> clear_values = {};
            clear_values[0].color = {{ 0.0f, 0.0f, 0.0f, 0.0f }};
            clear_values[1].depthStencil = { 1.0f, 0u };
            render_pass_info.clearValueCount = static_cast<uint32_t>(clear_values.size());
            render_pass_info.pClearValues = clear_values.data();

            vkCmdBeginRenderPass(m_command_buffers[i], &render_pass_info, VK_SUBPASS_CONTENTS_INLINE);
            
            m_b2e_pipeline->bind(m_command_buffers[i]);
            vkCmdDraw(m_command_buffers[i], 3, 1, 0, 0);
            vkCmdEndRenderPass(m_command_buffers[i]);
            VK_CHECK(vkEndCommandBuffer(m_command_buffers[i]));
        }
    }

    void App::m_draw_frame()
    {
        uint32_t image_index;
        auto result = m_b2e_swap_chain.acquire_next_image(&image_index);

        if (result != VK_SUCCESS && result != VK_SUBOPTIMAL_KHR)
        {
            throw std::runtime_error("Failed to acquire swap chain");
        }

        result = m_b2e_swap_chain.submit_command_buffers(&m_command_buffers[image_index], &image_index);
        VK_CHECK(result);
    }
}