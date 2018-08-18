#pragma once
#include <string>
#include <SDL2/SDL.h>


class IDisplay {
public:
    IDisplay(int width, int height, const std::string& title);
    virtual ~IDisplay();

    void swapBuffers();
    void update();

    bool isClosed() {return this->m_isClosed;}
    void clear(float r, float g, float b, float a);
private:    

    SDL_Window* m_window;
    SDL_GLContext m_context;
    bool m_isClosed;
};