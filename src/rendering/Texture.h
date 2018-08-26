#pragma once
#include <SDL2/SDL_image.h>
#include <string> 
#include <GL/glew.h>

class Texture {

public:
    Texture(std::string path);
    ~Texture();
    void load();

    void bind(unsigned int unit);

private:
    GLuint m_id;
    SDL_Surface* m_image;
    std::string m_path;
};