#include "b2e_model.h"

#include <cassert>
#include <cstring>

namespace b2e
{
    B2eModel::B2eModel(B2eDevice &device, const std::vector<Vertex> &vertices) : m_b2e_device(device)
    {
        m_create_vertex_buffers(vertices);
    }

    B2eModel::~B2eModel()
    {
        vkDestroyBuffer(m_b2e_device.device(), m_vertex_buffer, nullptr);
        vkFreeMemory(m_b2e_device.device(), m_vertex_buffer_memory, nullptr);
    }

    void B2eModel::bind(VkCommandBuffer command_buffer)
    {
        VkBuffer buffers[] = { m_vertex_buffer };
        VkDeviceSize offsets[] = { 0 };
        vkCmdBindVertexBuffers(command_buffer, 0, 1, buffers, offsets);
    }

    void B2eModel::draw(VkCommandBuffer command_buffer)
    {
        vkCmdDraw(command_buffer, m_vertex_count, 1, 0, 0);
    }

    void B2eModel::m_create_vertex_buffers(const std::vector<Vertex> &vertices)
    {
        m_vertex_count = static_cast<uint32_t>(vertices.size());
        assert(m_vertex_count >= 3 && "Vertex count must be at least 3");
        VkDeviceSize buffer_size = sizeof(vertices[0]) * m_vertex_count;

        m_b2e_device.create_buffer(
            buffer_size, 
            VK_BUFFER_USAGE_VERTEX_BUFFER_BIT,
            VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
            m_vertex_buffer, 
            m_vertex_buffer_memory
        );

        void *data;
        vkMapMemory(m_b2e_device.device(), m_vertex_buffer_memory, 0, buffer_size, 0, &data);
        memcpy(data, vertices.data(), static_cast<size_t>(buffer_size));
        vkUnmapMemory(m_b2e_device.device(), m_vertex_buffer_memory);
    }

    std::vector<VkVertexInputBindingDescription> B2eModel::Vertex::get_binding_descriptions()
    {
        return {
            { 0, sizeof(Vertex), VK_VERTEX_INPUT_RATE_VERTEX }
        };
    }

    std::vector<VkVertexInputAttributeDescription> B2eModel::Vertex::get_attribute_descriptions()
    {
        return {
            { 0, 0, VK_FORMAT_R32G32B32_SFLOAT, offsetof(Vertex, position) },
            { 1, 0, VK_FORMAT_R32G32B32_SFLOAT, offsetof(Vertex, color) }
        };
    }
}