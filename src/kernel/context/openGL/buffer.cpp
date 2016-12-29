#include <kernel/context/openGL/buffer.h>
#include <GL/glew.h>

namespace reboot_kernel_opengl{
    void Buffer::create(float* data, unsigned count) {
        glGenBuffers(1,&m_ID);
        bind();
        glBindBuffer(GL_ARRAY_BUFFER, m_ID);
        glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), data, GL_STATIC_DRAW);
        unbind();
    }
    Buffer::~Buffer() {
        glDeleteBuffers(1, &m_ID);
    }
    void Buffer::bind() {
        glBindBuffer(GL_ARRAY_BUFFER,m_ID);
    }
    void Buffer::unbind() {
        glBindBuffer(GL_ARRAY_BUFFER,0);
    }
}