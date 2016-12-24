#include <driver/mesh/mesh.h>
#include <driver/context.h>

namespace reboot_driver{
    Mesh::Mesh() {

    }
    Mesh::~Mesh() {
        delete IBO;
        delete VBO;
//        delete VAO;
    }

    void Mesh::bind() {
        VBO->bind();
    }

    void Mesh::unbind() {
        VBO->unbind();
    }

    void Mesh::create(unsigned vertexLocation, float *vertexData, int vertexCount, unsigned componentCount,
                    unsigned *vertexIndex, int indexCount) {
        VBO = Context::current->createVBO();
        VBO->bind();
        setBuffer(vertexLocation,vertexData,vertexCount, componentCount);
        VBO->unbind();
        IBO = Context::current->createIBO(vertexIndex,indexCount);
    }

    void Mesh::setBuffer(unsigned location, float *data, int count, unsigned componentCount) {
        reboot_kernel::ComponentBuffer buffer(data, count, componentCount);
        VBO->addBuffer(&buffer,location);
    }
}