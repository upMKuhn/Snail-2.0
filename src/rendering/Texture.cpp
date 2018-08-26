#include "Texture.h"
#include <iostream>

Texture::Texture(std::string path) {
    this->m_path = path;
    this->load();
}

void Texture::load() {
    const char* path = this->m_path.c_str();
    this->m_image = IMG_Load(path);
    
    if(this->m_image == NULL)
    {
        std::cout << "Could not load image: " << SDL_GetError() << '\n';
    }

    glGenTextures(1, &this->m_id);
    glBindTexture(GL_TEXTURE_2D, this->m_id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER , GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER , GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, this->m_image->w, this->m_image->h, 0, GL_RGB, GL_UNSIGNED_BYTE, this->m_image->pixels);

}

void Texture::bind(unsigned int unit) {
    glActiveTexture(GL_TEXTURE0 + unit);
    glBindTexture(GL_TEXTURE_2D, this->m_id);
}

Texture::~Texture() {
    SDL_FreeSurface(this->m_image);
}