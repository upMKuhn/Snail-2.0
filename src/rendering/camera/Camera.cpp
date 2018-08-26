#include "Camera.h"

Camera::Camera(      
        float aspect, 
        glm::vec3 position, 
        glm::vec3 rotation, 
        float fov, 
        float zNear, 
        float zFar
) {
    m_position = position;
    m_rotation = rotation;
    
    m_up = glm::vec3(0, 1, 0);
    m_forward = glm::vec3(0, 0, 1);

    updatePerspective(aspect, fov, zNear, zFar);
    
}


glm::mat4 Camera::getViewProjection() const {

    glm::mat4 rotX = glm::rotate(m_rotation.x, glm::vec3(1, 0, 0));
    glm::mat4 rotY = glm::rotate(m_rotation.y, glm::vec3(0, 1, 0));
    glm::mat4 rotZ = glm::rotate(m_rotation.z, glm::vec3(0, 0, 1));
    glm::mat4 rotMat = rotZ * rotY * rotX;

    return rotMat * (m_perspective * glm::lookAt(m_position, m_position + m_forward, m_up));
}

void Camera::updatePerspective(float aspect, float fov, float zNear, float zFar) {
    m_perspective = glm::perspective(fov, aspect, zNear, zFar);

}
