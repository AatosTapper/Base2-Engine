#include "b2e_window.h"

#include "VK_CHECK.h"

namespace b2e
{
    B2eWindow::B2eWindow(uint32_t w, uint32_t h, const std::string &name) : m_width(w), m_height(h), m_name(name)
    {
        m_init_window();
    }

    B2eWindow::~B2eWindow()
    {
        glfwDestroyWindow(m_window);
        glfwTerminate();
    }

    void B2eWindow::m_init_window()
    {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

        m_window = glfwCreateWindow(m_width, m_height, m_name.c_str(), nullptr, nullptr);
        glfwSetWindowUserPointer(m_window, this);
        glfwSetFramebufferSizeCallback(m_window, framebuffer_resize_callback);
    }

    void B2eWindow::create_window_surface(VkInstance instance, VkSurfaceKHR *surface)
    {
        VK_CHECK(glfwCreateWindowSurface(instance, m_window, nullptr, surface));
    }

    void B2eWindow::framebuffer_resize_callback(GLFWwindow *window, int width, int height)
    {
        B2eWindow *b2e_window = reinterpret_cast<B2eWindow *>(glfwGetWindowUserPointer(window));
        b2e_window->m_framebuffer_resized = true;
        b2e_window->m_width = width;
        b2e_window->m_height = height;
    }
}