#include "Mesh.h"
#include <vector>


Mesh::Mesh(Vertex* verticies, unsigned int numVertecies) {

    m_drawCount = numVertecies;

    std::vector<glm::vec3> positions;
    std::vector<glm::vec2> textCoords;

    textCoords.reserve(numVertecies);
    positions.reserve(numVertecies);

    for(int i = 0; i < numVertecies; i++) {
        positions.push_back(verticies[i].pos);
        textCoords.push_back(verticies[i].textCoord);
    }

    glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffer);

    this->bindBuffer(POSITION_VB, positions, 3);
    this->bindBuffer(TEXTCOORD_VB, textCoords, 2);

}

void Mesh::Draw(){
    glBindVertexArray(m_vertexArrayObject);
    glDrawArrays(GL_TRIANGLES, 0, m_drawCount);
    glBindVertexArray(0);
}

template<typename DataType>
void Mesh::bindBuffer(unsigned int bufferType, std::vector<DataType> data, unsigned int vecSize) {
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffer[bufferType]);
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(data[0]), &data[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(bufferType);
    glVertexAttribPointer(bufferType, vecSize, GL_FLOAT, GL_FALSE, 0, 0);
    glBindVertexArray(bufferType);
}

Mesh::~Mesh() {
    glDeleteVertexArrays(1, &m_vertexArrayObject);
}