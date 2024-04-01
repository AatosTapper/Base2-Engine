#include "app.h"

namespace b2e
{
    void App::run()
    {
        while (!m_b2e_window.should_close())
        {
            glfwPollEvents();
        }
    }
}