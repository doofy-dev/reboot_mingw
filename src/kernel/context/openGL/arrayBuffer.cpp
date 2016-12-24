#include <kernel/context/openGL/arrayBuffer.h>
#include <GL/glew.h>

namespace reboot_kernel_opengl {
    void ArrayBuffer::create() {
        glGenBuffers(1, &m_BufferID);
        bind();
        glBufferData(GL_ARRAY_BUFFER, m_Count * sizeof(float), m_Data, GL_STATIC_DRAW);
        unbind();
    }

    void ArrayBuffer::clean() {
        glDeleteBuffers(1, &m_BufferID);
        delete[] m_Data;
    }
    void ArrayBuffer::bind() {
        glBindBuffer(GL_ARRAY_BUFFER,m_BufferID);
    }
    void ArrayBuffer::unbind() {
        glBindBuffer(GL_ARRAY_BUFFER,0);
    }


}