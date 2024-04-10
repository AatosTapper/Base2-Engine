#include "b2e_camera.h"

#include "glm/gtc/matrix_transform.hpp"

#define WORLD_UP glm::vec3(0.0f, 1.0f, 0.0f)
#define FOV 85.0f

namespace b2e
{
    B2eCamera::B2eCamera(const float aspect_ratio) : 
        pitch(0.0f), yaw(90.0f),
        m_position(glm::vec3(0.0f)), 
        m_front(glm::vec3(0.0f, 0.0f, 1.0f)), 
        m_delta_pos(glm::vec3(0.0f)),
        m_vp_mat(std::make_unique<glm::mat4>(1.0f))
    {
        update(aspect_ratio);
    }

    void B2eCamera::update(const float aspect_ratio)
    {
        m_position += m_delta_pos;
        m_delta_pos = glm::vec3(0.0f);
        m_update_direction();
        m_front = m_direction;
        m_up = glm::normalize(glm::cross(m_direction, glm::normalize(glm::cross(WORLD_UP, m_direction))));
        m_right = glm::normalize(glm::cross(m_front, m_up));
        m_view = glm::lookAtRH(m_position, m_position + m_front, m_up);

        glm::mat4 projection = glm::perspective(glm::radians(FOV), aspect_ratio, 0.1f, 1000.0f);
        projection[1][1] *= -1;
        *m_vp_mat = projection * m_view;
        
        *m_vp_mat = glm::mat4(1.0f); // for debugging
    }

    void B2eCamera::forward(const float amount)
    {
        m_delta_pos += amount * m_front;
    }

    void B2eCamera::back(const float amount)
    {
        m_delta_pos -= amount * m_front;
    }

    void B2eCamera::left(const float amount)
    {
        m_delta_pos -= amount * m_right;
    }

    void B2eCamera::right(const float amount)
    {
        m_delta_pos += amount * m_right;
    }

    void B2eCamera::up(const float amount)
    {
        m_delta_pos -= amount * WORLD_UP;
    }

    void B2eCamera::down(const float amount)
    {
        m_delta_pos += amount * WORLD_UP;
    }

    void B2eCamera::m_update_direction()
    {
        m_direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        m_direction.y = sin(glm::radians(pitch));
        m_direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
        m_direction = glm::normalize(m_direction);
    }
}