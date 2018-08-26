#pragma once
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include "camera/Camera.h"
class Transform {

public:

    Transform(const glm::vec3& pos = glm::vec3(), const glm::vec3& rotation = glm::vec3(), const glm::vec3& scale = glm::vec3(1.0f, 1.0f, 1.0f)) {
        this->m_pos = pos;
        this->m_rot = rotation;
        this->m_scale = scale;
    }
    
    inline glm::mat4 getModel() const {
        
        glm::mat4 posMat = glm::translate(m_pos);
        glm::mat4 scaleMat = glm::scale(m_scale);
        glm::mat4 rotX = glm::rotate(m_rot.x, glm::vec3(1, 0, 0));
        glm::mat4 rotY = glm::rotate(m_rot.y, glm::vec3(0, 1, 0));
        glm::mat4 rotZ = glm::rotate(m_rot.z, glm::vec3(0, 0, 1));

        glm::mat4 rotMat = rotZ * rotY * rotX;

        
        return posMat * rotMat * scaleMat;
    }

    inline glm::mat4 getModelViewProjection(const Camera& camera) const {
        glm::mat4 VP = camera.getViewProjection();
        glm::mat4 model = getModel();

        return VP * model;
    }

    inline glm::vec3& getPos() { return m_pos; }
    inline glm::vec3& getRot() { return m_rot; }
    inline glm::vec3& getScale() { return m_scale; }

    inline void setPos(glm::vec3& pos) { m_pos = pos; }
    inline void setRot(glm::vec3& rot) { m_rot = rot; }
    inline void setScale(glm::vec3& scale) { m_scale = scale; }

protected:

    glm::vec3 m_pos;
    glm::vec3 m_rot;
    glm::vec3 m_scale;

};