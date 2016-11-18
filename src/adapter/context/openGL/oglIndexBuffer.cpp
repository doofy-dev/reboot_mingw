#include <adapter/context/openGL/oglIndexBuffer.h>
#include <GL/glew.h>
namespace reboot_adapter{
    OGLIndexBuffer::~OGLIndexBuffer() {
        glDeleteBuffers(1,&m_BufferID);
    }

    void OGLIndexBuffer::create() {
        glGenBuffers(1, &m_BufferID);
        bind();
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_Count * sizeof(GLuint), m_Data, GL_STATIC_DRAW);
        unbind();
    }

    void OGLIndexBuffer::bind() {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferID);
    }

    void OGLIndexBuffer::unbind() {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
}