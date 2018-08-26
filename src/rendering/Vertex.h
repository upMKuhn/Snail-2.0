
#pragma once
#include <glm/glm.hpp>

class Vertex {
public:

    Vertex(const glm::vec3& pos, const glm::vec2 &textCoord) {
        this->pos = pos;
        this->textCoord = textCoord;
    }

    glm::vec3 pos;
    glm::vec2 textCoord;
};