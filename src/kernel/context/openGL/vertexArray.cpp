#include <kernel/context/openGL/vertexArray.h>

#include <GL/glew.h>

namespace reboot_kernel_opengl{
    VertexArray::~VertexArray() {
        for (unsigned int i = 0; i < m_Buffers.size(); i++) {
            delete m_Buffers[i];
        }
    }
    void VertexArray::addBuffer(reboot_kernel::Buffer *buffer, unsigned index) {
        bind();
        buffer->bind();
        errorCheck("vao bind");
        glEnableVertexAttribArray(index);
        errorCheck("vao attribarray");
        glVertexAttribPointer(index,buffer->m_ComponentCount,GL_FLOAT,GL_FALSE,0,0);
        errorCheck("vao attribpointer");
        buffer->unbind();
        unbind();
        errorCheck("vao unbind");
    }
    void VertexArray::create() {
        glGenVertexArrays(1, &m_ID);
    }
    void VertexArray::bind() {
        glBindVertexArray(m_ID);
    }
    void VertexArray::unbind() {
        glBindVertexArray(0);
    }
}