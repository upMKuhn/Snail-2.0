#include "./OpenGLShader.h"
#include <iostream>
#include <fstream>

OpenGLShader::OpenGLShader(const std::string& filename) {
    m_program = glCreateProgram();

    m_shaders[0] = this->createShader(this->loadShader(filename + ".vs"), GL_VERTEX_SHADER);
    m_shaders[1] = createShader(loadShader(filename + ".fs"), GL_FRAGMENT_SHADER);

    for(unsigned int i = 0; i < NUM_SHADERS; i++)
        glAttachShader(m_program, m_shaders[i]);

    glBindAttribLocation(m_program, 0, "position");
    glBindAttribLocation(m_program, 1, "textureCoords");
    
    glLinkProgram(m_program);
    this->checkShaderError(m_program, GL_LINK_STATUS, true, "ERROR: Program linking failed:  ");

    glValidateProgram(m_program);
    this->checkShaderError(m_program, GL_VALIDATE_STATUS, true, "ERROR: Program is invalid:  ");

    m_uniforms[TRANSFORM_U] = glGetUniformLocation(m_program, "transform");
}



void OpenGLShader::bindShader() {
    glUseProgram(m_program);
}


void OpenGLShader::update(const Transform& transform, const Camera& camera) {

    glm::mat4 mvp = transform.getModelViewProjection(camera);

    glUniformMatrix4fv(m_uniforms[TRANSFORM_U], 1, GL_FALSE, &mvp[0][0]);
}

std::string OpenGLShader::loadShader(const std::string& fileName)
{
    std::ifstream file;
    file.open((fileName).c_str());

    std::string output;
    std::string line;

    if(file.is_open())
    {
        while(file.good())
        {
            getline(file, line);
			output.append(line + "\n");
        }
    }
    else
    {
		std::cerr << "Unable to load shader: " << fileName << std::endl;
    }

    return output;
}

void OpenGLShader::checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage)
{
    GLint success = 0;
    GLchar error[1024] = { 0 };

    if(isProgram)
        glGetProgramiv(shader, flag, &success);
    else
        glGetShaderiv(shader, flag, &success);

    if(success == GL_FALSE)
    {
        if(isProgram)
            glGetProgramInfoLog(shader, sizeof(error), NULL, error);
        else
            glGetShaderInfoLog(shader, sizeof(error), NULL, error);

        std::cerr << errorMessage << ": '" << error << "'" << std::endl;
    }
}

GLuint OpenGLShader::createShader(const std::string& src, GLenum shaderType) {
    GLuint shader = glCreateShader(shaderType);

    if(shader == 0)
        std::cerr << "Error: Shader creation failed :mface";

    const GLchar* shaderSource[1];
    GLint srcLength[1];
    shaderSource[0] = src.c_str();
    srcLength[0] = src.length();
    
    glShaderSource(shader, 1, shaderSource, srcLength);
    glCompileShader(shader);

    this->checkShaderError(shader, GL_COMPILE_STATUS, false, "Error: shader compilation failed: ");

    return shader;
}

OpenGLShader::~OpenGLShader() {
    for(unsigned int i = 0; i < NUM_SHADERS; i++){
        glDetachShader(m_program, m_shaders[i]);
        glDeleteShader(m_shaders[i]);
    }    

    glDeleteProgram(m_program);
}