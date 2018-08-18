#pragma once
#include <string>
#include <GL/glew.h>


class OpenGLShader{

public:
    OpenGLShader(const std::string& filename);
    virtual ~OpenGLShader();
    void bindShader();

protected:
private:
    std::string loadShader(const std::string& fileName);
    void checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
    GLuint createShader(const std::string& src, GLenum shaderType);

static const unsigned int NUM_SHADERS = 2;
GLuint m_program;
GLuint m_shaders[NUM_SHADERS];

};