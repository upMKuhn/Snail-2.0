#include "main.h"
#include <iostream>
#include <GL/glew.h>
#include <rendering/OpenGLShader.h>
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480


int static doSDL() {
    SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "could not initialize sdl2: %s\n", SDL_GetError());
		return 1;
	}
	if (window == NULL) {
		fprintf(stderr, "could not create window: %s\n", SDL_GetError());
		return 1;
	}
	screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
	SDL_UpdateWindowSurface(window);
	SDL_Delay(2000);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}

int main(int argc, char *argv[]) {
    IDisplay display(640, 480, "hello");
    OpenGLShader shader("./res/basicShader");
    while(!display.isClosed()) {
        display.clear(0.0f, 0.15f, 0.3f, 1.0f);

        display.update();
    }
    return 0;
}
