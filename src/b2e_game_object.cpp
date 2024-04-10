#include "b2e_game_object.h"


#include <glm/gtc/type_ptr.hpp>

namespace b2e
{
    glm::mat4 Transform3dComponent::mat4() const
    {
        glm::mat4 matrix(1.0f);
        matrix = glm::scale(matrix, scale);
        matrix = glm::translate(matrix, translation);
        return matrix;
    }
}