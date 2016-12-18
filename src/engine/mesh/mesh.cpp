#include <driver/mesh/mesh.h>

namespace reboot_driver{
    Mesh::Mesh() {

    }
    Mesh::~Mesh() {
        delete IBO;
        delete VAO;
        delete VBO;
    }

    void Mesh::bind() {
        VBO->bind();
    }

    void Mesh::unbind() {
        VBO->unbind();
    }

    void Mesh::load(unsigned vertexLocation, float *vertexData, int vertexCount, unsigned componentCount,
                    unsigned *vertexIndex, int indexCount) {

    }

    void Mesh::addBuffer(unsigned location, float *data, int count, unsigned componentCount) {

    }
}