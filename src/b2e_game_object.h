#pragma once

#include "b2e_model.h"

#include <glm/glm.hpp>

#include <memory>

namespace b2e
{
    struct Transform3dComponent
    {
        glm::vec3 translation{0.0f};
        glm::vec3 scale{1.0f};

        glm::mat4 mat4() const;
    };

    class B2eGameObject
    {
    public:
        using id_t = unsigned int;

        inline static B2eGameObject create_game_object()
        {
            static id_t current_id = 0;
            return B2eGameObject(current_id++);
        }

        B2eGameObject(const B2eGameObject&) = delete;
        B2eGameObject &operator=(const B2eGameObject&) = delete;
        B2eGameObject(B2eGameObject&&) = default;
        B2eGameObject &operator=(B2eGameObject&&) = default;

        inline id_t get_id() { return m_id; }

        std::shared_ptr<B2eModel> model{};
        glm::vec3 color{}; // not in use rn
        Transform3dComponent transform;

    private:
        B2eGameObject(id_t obj_id) : m_id(obj_id) {}

        id_t m_id;
    };
}
