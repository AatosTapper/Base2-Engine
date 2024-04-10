#pragma once

#include "b2e_device.h"

#include <vector>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <vulkan/vulkan.h>

namespace b2e
{
    class B2eModel
    {
    public:
        struct Vertex
        {
            glm::vec3 position;
            glm::vec3 color;

            static std::vector<VkVertexInputBindingDescription> get_binding_descriptions();
            static std::vector<VkVertexInputAttributeDescription> get_attribute_descriptions();
        };

        B2eModel(B2eDevice &device, const std::vector<Vertex> &vertices);
        ~B2eModel();

        B2eModel(const B2eModel&) = delete;
        B2eModel &operator=(const B2eModel&) = delete;
        
        void bind(VkCommandBuffer command_buffer);
        void draw(VkCommandBuffer command_buffer);

    private:
        B2eDevice &m_b2e_device;
        VkBuffer m_vertex_buffer;
        VkDeviceMemory m_vertex_buffer_memory;
        uint32_t m_vertex_count;

        void m_create_vertex_buffers(const std::vector<Vertex> &vertices);
    };
}