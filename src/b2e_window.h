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

        inline float get_aspect_ratio() const { return static_cast<float>(m_width) / static_cast<float>(m_height); }
        inline bool should_close() const { return glfwWindowShouldClose(m_window); }
        inline VkExtent2D get_extent() const { return { static_cast<uint32_t>(m_width), static_cast<uint32_t>(m_height) }; }
        inline bool was_window_resized() const { return m_framebuffer_resized; }
        inline void reset_window_resized_flag() { m_framebuffer_resized = false; }
        inline GLFWwindow *get_window() const { return m_window; }

        void create_window_surface(VkInstance instance, VkSurfaceKHR *surface);
        
    private:
        uint32_t m_width;
        uint32_t m_height;
        bool m_framebuffer_resized = false;

        std::string m_name;
        GLFWwindow *m_window;


        void m_init_window();

        static void framebuffer_resize_callback(GLFWwindow *window, int width, int height);
    };
}