#pragma once

// provides a generic 3D camera controller with mouse and keyboard already setup

#include "b2e_camera.h"
#include <GLFW/glfw3.h>

namespace b2e
{
    class B2eCameraController
    {
    public:
        B2eCameraController(GLFWwindow *window, float SW, float SH);

        float movement_speed;
        float mouse_sensitivity;

        void update(GLFWwindow *window, B2eCamera &camera);
    };
}