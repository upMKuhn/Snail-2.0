#include "main.h"
#include <iostream>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <rendering/OpenGLShader.h>
#include <rendering/Mesh.h>
#include <rendering/Vertex.h>
#include <rendering/Texture.h>
#include <rendering/Transform.hpp>
#include <rendering/camera/Camera.h>
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main(int argc, char *argv[]) {

    const float WIDTH = 1028;
    const float HEIGHT = 648;
    IDisplay display(WIDTH, HEIGHT, "hello");
    OpenGLShader shader("./res/basicShader");

    Vertex vertecies[] = {
        Vertex(glm::vec3(-0.5, -0.5, 0),    glm::vec2(0, 0)),
        Vertex(glm::vec3(0, 0.5, 0),        glm::vec2(0.5, 1)),
        Vertex(glm::vec3(0.5, -0.5, 0),     glm::vec2(1, 0))
    };

    Texture wall("./res/wall.jpeg");
    Mesh mesh(vertecies, sizeof(vertecies)/sizeof(vertecies[0]));
    Camera camera( WIDTH / HEIGHT, glm::vec3(-0.3, 0 ,-3));
    Transform transform;

    float counter = 0.0f;

    while(!display.isClosed()) {
        display.clear(0.0f, 0.15f, 0.3f, 1.0f);
        transform.getPos().x = sinf(counter);
        transform.getRot().x = counter*5;

        shader.bindShader();
        shader.update(transform, camera);
        mesh.Draw();
        wall.bind(0);

        display.update();
        counter += 0.01f;
    }
    return 0;
}
