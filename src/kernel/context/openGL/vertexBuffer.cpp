#include <kernel/context/openGL/vertexBuffer.h>
#include <GL/glew.h>

namespace reboot_kernel_opengl{
    VertexBuffer::VertexBuffer():reboot_kernel::VertexBuffer() {
        glGenVertexArrays(1, &m_BufferID);
    }
    void VertexBuffer::addBuffer(reboot_kernel::Buffer* buffer, unsigned index){
        bind();
        buffer->bind();
        m_Buffers.push_back(buffer);
        glEnableVertexAttribArray(index);
        glVertexAttribPointer(index, buffer->getCount(), GL_FLOAT, GL_FALSE, 0, 0);

        buffer->unbind();
        unbind();
    }
    VertexBuffer::~VertexBuffer() {
        for (unsigned int i = 0; i < m_Buffers.size(); i++) {
            delete m_Buffers[i];
        }
    }
    void VertexBuffer::bind() {
        glBindVertexArray(m_BufferID);
    }
    void VertexBuffer::unbind() {
        glBindVertexArray(0);
    }
}