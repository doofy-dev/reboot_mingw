#include <driver/mesh/mesh.h>
#include <driver/context.h>

namespace reboot_driver{
    Mesh::Mesh() {

    }
    Mesh::~Mesh() {
        delete IBO;
        delete VAO;
    }

    void Mesh::bind() {
        VAO->bind();
        IBO->bind();

        m_Material->bind();
    }

    void Mesh::unbind() {
        m_Material->unbind();
        IBO->unbind();
        VAO->unbind();
    }

    void Mesh::create(unsigned vertexLocation, float *vertexData, int vertexCount, unsigned componentCount,
                    unsigned *vertexIndex, int indexCount) {
        VAO = Context::current->createVAO();
        errorCheck("after VBO");
        VAO->bind();
        errorCheck("VBO bind");
        setBuffer(vertexLocation,vertexData,vertexCount, componentCount);
        errorCheck("setbuffer after");
        VAO->unbind();
        errorCheck("VBO unbind");
        IBO = Context::current->createIBO(vertexIndex,indexCount);
        errorCheck("after IBO");
    }

    void Mesh::setBuffer(unsigned location, float *data, int count, unsigned componentCount) {
        reboot_kernel::Buffer *buffer = Context::current->createBuffer(data, (unsigned)count, componentCount);
        errorCheck("component buffer");
        VAO->addBuffer(buffer,location);
        errorCheck("addbuffer");
    }
}