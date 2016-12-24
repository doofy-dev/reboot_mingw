#include <kernel/context/openGL/indexBuffer.h>
#include <GL/glew.h>

namespace reboot_kernel_opengl{

    void IndexBuffer::create() {
        glGenBuffers(1, &m_BufferID);
        bind();

        glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_Count * sizeof(GLuint), m_Data, GL_STATIC_DRAW);
        unbind();
    }

    void IndexBuffer::bind() {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferID);
    }

    void IndexBuffer::unbind() {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
    void IndexBuffer::clean(){
        glDeleteBuffers(1,&m_BufferID);
    }
}