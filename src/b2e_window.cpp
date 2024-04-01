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
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        m_window = glfwCreateWindow(m_width, m_height, m_name.c_str(), nullptr, nullptr);
    }

    void B2eWindow::create_window_surface(VkInstance instance, VkSurfaceKHR *surface)
    {
        VK_CHECK(glfwCreateWindowSurface(instance, m_window, nullptr, surface));
    }
}