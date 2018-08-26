
#include "Vertex.h"
#include <GL/glew.h>
#include <vector>
class Mesh {

public:
    Mesh(Vertex* verticies, unsigned int numVertecies);
    void Draw();

    ~Mesh();
private:

    template<typename DataType>
    void bindBuffer(unsigned int bufferType, std::vector<DataType> data, unsigned int vecSize);

    enum {
        POSITION_VB,
        TEXTCOORD_VB,

        NUM_BUFFERS
    };

    glm::vec2 m_texCoord;

    unsigned int m_drawCount;
    GLuint m_vertexArrayObject;
    GLuint m_vertexArrayBuffer[NUM_BUFFERS];
};