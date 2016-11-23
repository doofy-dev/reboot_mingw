#include <kernel/context/openGL/oglVertexArray.h>
#include <GL/glew.h>

namespace reboot_kernel{
    OGLVertexArray::OGLVertexArray():VertexArray() {
        glGenVertexArrays(1, &m_BufferID);
    }
    void OGLVertexArray::addBuffer(Buffer* buffer, unsigned index){
        bind();
        buffer->bind();
        m_Buffers.push_back(buffer);
        glEnableVertexAttribArray(index);
        glVertexAttribPointer(index, buffer->getCount(), GL_FLOAT, GL_FALSE, 0, 0);

        buffer->unbind();
        unbind();
    }
    OGLVertexArray::~OGLVertexArray() {
        for (unsigned int i = 0; i < m_Buffers.size(); i++) {
            delete m_Buffers[i];
        }
    }
    void OGLVertexArray::bind() {
        glBindVertexArray(m_BufferID);
    }
    void OGLVertexArray::unbind() {
        glBindVertexArray(0);
    }
}