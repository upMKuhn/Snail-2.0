#pragma once
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

class Camera {

public:

    Camera(
        float aspect, 
        glm::vec3 position = glm::vec3(0, 0, -3), 
        glm::vec3 rotation = glm::vec3(0, 0, 0), 
        float fov = 70.0f, 
        float zNear = 1.0f, 
        float zFar = 1000.0f
    ) ;


    void updatePerspective(float aspect, float fov = 70.0f, float zNear = 0.01f, float zFar = 1000.0f);

    glm::mat4 getViewProjection() const;

private:

    glm::mat4 m_perspective;

    glm::vec3 m_position;
    glm::vec3 m_rotation;
    glm::vec3 m_up;
    glm::vec3 m_forward;

};