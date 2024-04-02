#pragma once

#include "b2e_window.h"
#include "b2e_pipeline.h"
#include "b2e_device.h"
#include "b2e_swap_chain.h"

#include <memory>
#include <vector>

namespace b2e
{
    class App
    {
    public:
        App();
        ~App();

        App(const App&) = delete;
        App &operator=(const App&) = delete;

        static constexpr uint32_t WIDTH = 1280;
        static constexpr uint32_t HEIGHT = 720;

        void run();

    private:
        B2eWindow m_b2e_window = { WIDTH, HEIGHT, "Vulkan" };
        B2eDevice m_b2e_device = { m_b2e_window };
        B2eSwapChain m_b2e_swap_chain = { m_b2e_device, m_b2e_window.get_extent() };

        std::unique_ptr<B2ePipeline> m_b2e_pipeline;
        VkPipelineLayout m_pipeline_layout;
        std::vector<VkCommandBuffer> m_command_buffers;

        void m_create_pipeline_layout();
        void m_create_pipeline();
        void m_create_command_buffers();
        void m_draw_frame();
    };
}
