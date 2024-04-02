#pragma once

#include <string>
#include <vector>

#include "b2e_device.h"

#define BACK_FACE_CULLING false

namespace b2e
{
    struct PipelineConfigInfo 
    {
        VkViewport viewport;
        VkRect2D scissor;
        VkPipelineInputAssemblyStateCreateInfo input_assembly_info;
        VkPipelineRasterizationStateCreateInfo rasterization_info;
        VkPipelineMultisampleStateCreateInfo multisample_info;
        VkPipelineColorBlendAttachmentState color_blend_attachment;
        VkPipelineColorBlendStateCreateInfo color_blend_info;
        VkPipelineDepthStencilStateCreateInfo depth_stencil_info;
        VkPipelineLayout pipeline_layout = nullptr;
        VkRenderPass render_pass = nullptr;
        uint32_t subpass = 0;
    };

    class B2ePipeline
    {
    public:
        B2ePipeline(
            B2eDevice &b2e_device, 
            const std::string &vert_path, 
            const std::string &frag_path, 
            const PipelineConfigInfo &config_info);
        ~B2ePipeline();

        B2ePipeline(const B2ePipeline&) = delete;
        void operator=(const B2ePipeline&) = delete;

        void bind(VkCommandBuffer command_buffer);
        static PipelineConfigInfo default_pipeline_config_info(uint32_t width, uint32_t height);

    private:
        static std::vector<char> m_read_file(const std::string &filepath);
        void m_create_graphics_pipeline(
            const std::string &vert_path, 
            const std::string &frag_path, 
            const PipelineConfigInfo &config_info);
        void m_create_shader_module(const std::vector<char> &code, VkShaderModule *shader_module);
            
        B2eDevice &m_b2e_device;
        VkPipeline m_graphics_pipeline;
        VkShaderModule m_vert_shader_module;
        VkShaderModule m_frag_shader_module;
    };
}
