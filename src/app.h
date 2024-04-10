#pragma once

#include "b2e_window.h"
#include "b2e_pipeline.h"
#include "b2e_device.h"
#include "b2e_camera.h"
#include "b2e_camera_controller.h"
#include "b2e_game_object.h"
#include "b2e_renderer.h"

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
        B2eRenderer m_b2e_renderer = { m_b2e_window, m_b2e_device };

        std::unique_ptr<B2ePipeline> m_b2e_pipeline;
        VkPipelineLayout m_pipeline_layout;

        std::unique_ptr<B2eCamera> m_camera;
        std::unique_ptr<B2eCameraController> m_camera_controller;
        std::vector<B2eGameObject> m_game_objects;

        void m_load_game_objects();
        void m_create_pipeline_layout();
        void m_create_pipeline();
        void m_render_game_objects(VkCommandBuffer command_buffer);
    };
}
