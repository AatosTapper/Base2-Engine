#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

namespace b2e
{
    class B2eWindow
    {   
    public:
        B2eWindow(uint32_t w, uint32_t h, const std::string &name);
        ~B2eWindow();

        B2eWindow(const B2eWindow&) = delete;
        B2eWindow &operator=(const B2eWindow&) = delete;

        inline bool should_close() { return glfwWindowShouldClose(m_window); }
        inline VkExtent2D get_extent() { return { static_cast<uint32_t>(m_width), static_cast<uint32_t>(m_height) }; }
        void create_window_surface(VkInstance instance, VkSurfaceKHR *surface);
        
    private:
        GLFWwindow *m_window;
        const uint32_t m_width;
        const uint32_t m_height;
        std::string m_name;

        void m_init_window();
    };
}