#include "app.h"
#include "VK_CHECK.h"

#include <array>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace b2e
{
    struct PushConstantData
    {
        glm::mat4 view_proj;
        glm::mat4 transform;
    };

    App::App()
        : m_camera(std::make_unique<B2eCamera>(m_b2e_window.get_aspect_ratio())),
        m_camera_controller(std::make_unique<B2eCameraController>(m_b2e_window.get_window(), m_b2e_window.get_extent().width, m_b2e_window.get_extent().height))
    {
        m_load_game_objects();
        m_create_pipeline_layout();
        m_create_pipeline();

        m_camera->set_position(glm::vec3(0.0f, 0.0f, 0.0f));
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
            if (auto command_buffer = m_b2e_renderer.begin_frame())
            {
                m_b2e_renderer.begin_swap_chain_render_pass(command_buffer);
                m_render_game_objects(command_buffer);
                m_b2e_renderer.end_swap_chain_render_pass(command_buffer);
                m_b2e_renderer.end_frame();
            }
            m_camera_controller->update(m_b2e_window.get_window(), *m_camera);
            m_camera->update(m_b2e_window.get_aspect_ratio());
        }

        vkDeviceWaitIdle(m_b2e_device.device());
    }

    void App::m_create_pipeline_layout()
    {
        VkPushConstantRange push_constant_range = {};
        push_constant_range.stageFlags = VK_SHADER_STAGE_VERTEX_BIT | VK_SHADER_STAGE_FRAGMENT_BIT;
        push_constant_range.offset = 0;
        push_constant_range.size = sizeof(PushConstantData);

        VkPipelineLayoutCreateInfo pipeline_layout_info = {};
        pipeline_layout_info.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
        pipeline_layout_info.setLayoutCount = 0;
        pipeline_layout_info.pSetLayouts = nullptr;
        pipeline_layout_info.pushConstantRangeCount = 1;
        pipeline_layout_info.pPushConstantRanges = &push_constant_range;

        VK_CHECK(vkCreatePipelineLayout(m_b2e_device.device(), &pipeline_layout_info, nullptr, &m_pipeline_layout));
    }

    void App::m_create_pipeline()
    {
        assert(m_pipeline_layout != nullptr);

        PipelineConfigInfo pipeline_config{};
        B2ePipeline::default_pipeline_config_info(pipeline_config);
        pipeline_config.render_pass = m_b2e_renderer.get_swap_chain_render_pass();
        pipeline_config.pipeline_layout = m_pipeline_layout;
        m_b2e_pipeline = std::make_unique<B2ePipeline>(m_b2e_device,
            "../shaders/SPIRV/default.vert.spv", 
            "../shaders/SPIRV/default.frag.spv",
            pipeline_config
        );
    }

    void App::m_load_game_objects()
    {
        std::vector<B2eModel::Vertex> vertices = {
            {{ 0.0f, -0.5f, 0.0f }, { 0.0f, 0.0f, 1.0f }},
            {{ 0.5f,  0.5f, 0.0f }, { 0.0f, 1.0f, 0.0f }},
            {{-0.5f,  0.5f, 0.0f }, { 1.0f, 0.0f, 0.0f }}
        };

        auto model = std::make_shared<B2eModel>(m_b2e_device, vertices);

        auto triangle = B2eGameObject::create_game_object();
        triangle.model = model;
        triangle.color = { 0.1f, 0.8f, 0.1f };
        triangle.transform.translation.x = 0.2f;

        m_game_objects.push_back(std::move(triangle));
    }

    void App::m_render_game_objects(VkCommandBuffer command_buffer)
    {
        m_b2e_pipeline->bind(command_buffer);
        for (auto &obj : m_game_objects)
        {
            PushConstantData model_view_proj = {
                .view_proj = *m_camera->get_vp_matrix(),
                .transform = obj.transform.mat4()
            };

            vkCmdPushConstants(
                command_buffer, 
                m_pipeline_layout, 
                VK_SHADER_STAGE_VERTEX_BIT | VK_SHADER_STAGE_FRAGMENT_BIT,
                0, 
                sizeof(PushConstantData),
                &model_view_proj
            );

            obj.model->bind(command_buffer);
            obj.model->draw(command_buffer);
        }
    }
}