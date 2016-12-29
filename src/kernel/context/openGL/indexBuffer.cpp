#include <kernel/context/openGL/indexBuffer.h>
#include <GL/glew.h>

namespace reboot_kernel_opengl {
    void IndexBuffer::create(unsigned *data, unsigned count) {
        m_Count=count;
        glGenBuffers(1, &m_ID);
        bind();
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned), data, GL_STATIC_DRAW);
        unbind();
    }

    IndexBuffer::~IndexBuffer() {
        glDeleteBuffers(1, &m_ID);
    }

    void IndexBuffer::bind() {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);

    }

    void IndexBuffer::unbind() {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

}