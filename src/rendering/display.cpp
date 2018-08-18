#include "display.h"
#include <GL/glew.h>
#include <iostream>

IDisplay::IDisplay(int width, int height, const std::string& title) { 
    std::cout << "constructed" << std::endl;
    
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		fprintf(stderr, "could not initialize sdl2: %s\n", SDL_GetError());
	}

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    this->m_window = SDL_CreateWindow(
        title.c_str(),
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
    this->m_context = SDL_GL_CreateContext(this->m_window);

    GLenum status = glewInit();

    if(status != GLEW_OK) {
        std::cerr << "Failed to init " << glewGetErrorString(status)  << std::endl;
    }

}

IDisplay::~IDisplay(){
    SDL_Quit();
}

void IDisplay::swapBuffers() {
    SDL_GL_SwapWindow(m_window);
}

void IDisplay::clear(float r, float g, float b, float a) {
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT);
}


void IDisplay::update() {
    SDL_GL_SwapWindow(m_window);
    SDL_Event e;

    while(SDL_PollEvent(&e)) {
        if(e.type == SDL_QUIT) {
            this->m_isClosed = true;
        } 
    }
}
