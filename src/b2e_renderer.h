#pragma once

#include "b2e_window.h"
#include "b2e_device.h"
#include "b2e_swap_chain.h"
#include "b2e_model.h"
#include "b2e_camera.h"
#include "b2e_camera_controller.h"

#include <memory>
#include <vector>
#include <cassert>

namespace b2e
{
    class B2eRenderer
    {
    public:
        B2eRenderer(B2eWindow &window, B2eDevice &device);
        ~B2eRenderer();

        B2eRenderer(const B2eRenderer&) = delete;
        B2eRenderer &operator=(const B2eRenderer&) = delete;

        VkCommandBuffer begin_frame();
        void end_frame();
        void begin_swap_chain_render_pass(VkCommandBuffer command_buffer);
        void end_swap_chain_render_pass(VkCommandBuffer command_buffer);
        
        inline VkRenderPass get_swap_chain_render_pass() const { return m_b2e_swap_chain->get_render_pass(); }
        inline bool is_frame_in_progress() const { return m_is_frame_started; }
        inline VkCommandBuffer get_current_command_buffer() const
        {
            assert(m_is_frame_started && "Cannot get command buffer when frame is not in progress");
            return m_command_buffers[m_current_image_index];
        }

    private:
        B2eWindow &m_b2e_window;
        B2eDevice &m_b2e_device;
        std::unique_ptr<B2eSwapChain> m_b2e_swap_chain;
        std::vector<VkCommandBuffer> m_command_buffers;

        uint32_t m_current_image_index;
        bool m_is_frame_started = false;

        void m_create_command_buffers();
        void m_free_command_buffers();
        void m_recreate_swap_chain();
    };
}