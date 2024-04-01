#pragma once

#include "b2e_window.h"
#include "b2e_pipeline.h"
#include "b2e_device.h"

namespace b2e
{
    class App
    {
    public:
        static constexpr uint32_t WIDTH = 1280;
        static constexpr uint32_t HEIGHT = 720;

        void run();
    private:
        B2eWindow m_b2e_window = { WIDTH, HEIGHT, "Vulkan" };
        B2eDevice m_b2e_device = { m_b2e_window };
        B2ePipeline m_b2e_pipeline = { 
            m_b2e_device,
            "../shaders/SPIRV/default.vert.spv", 
            "../shaders/SPIRV/default.frag.spv",
            B2ePipeline::default_pipeline_config_info(WIDTH, HEIGHT)};
    };
}
