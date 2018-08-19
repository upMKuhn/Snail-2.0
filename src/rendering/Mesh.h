
#include "Vertex.h"
#include <GL/glew.h>

class Mesh {

public:
    Mesh(Vertex* verticies, unsigned int numVertecies);
    void Draw();

    ~Mesh();
private:

    enum {
        POSITION_VB,

        NUM_BUFFERS
    };

    unsigned int m_drawCount;
    GLuint m_vertexArrayObject;
    GLuint m_vertexArrayBuffer[NUM_BUFFERS];
};