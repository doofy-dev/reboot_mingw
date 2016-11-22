#include <kernel/context/openGL/oglArrayBuffer.h>
#include <GL/glew.h>

namespace reboot_kernel {
    void OGLArrayBuffer::create() {
        glGenBuffers(1, &m_BufferID);
        bind();
        glBufferData(GL_ARRAY_BUFFER, m_Count * sizeof(float), m_Data, GL_STATIC_DRAW);
        unbind();
    }

    void OGLArrayBuffer::clean() {
        glDeleteBuffers(1, &m_BufferID);
        delete[] m_Data;
    }
    void OGLArrayBuffer::bind() {
        glBindBuffer(GL_ARRAY_BUFFER,m_BufferID);
    }
    void OGLArrayBuffer::unbind() {
        glBindBuffer(GL_ARRAY_BUFFER,0);
    }

}