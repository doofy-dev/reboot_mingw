#include <driver/context.h>
#include <kernel/canvas/window.h>

namespace reboot_driver {
    Context *Context::current= nullptr;

    Context::Context(BYTE contextType, BYTE canvasType)
            : m_ContextType(contextType), m_CanvastType(canvasType) {
        switch (canvasType) {
            case CANVAS_FRAME:
                break;
            case CANVAS_GLFW:
            default:
                m_Canvas = new reboot_kernel::Window();
                break;
        }
        current=this;
    }

    reboot_kernel::Buffer *Context::createBuffer(float* data, unsigned count, unsigned componentCount) {
        if (m_ContextType == CONTEXT_OPENGL4) {
            return new reboot_kernel_opengl::Buffer(data,count,componentCount);
        }
        return nullptr;
    }

    reboot_kernel::Buffer *Context::createFBO() {
        return nullptr;
    }

    reboot_kernel::VertexArray *Context::createVAO() {
        if (m_ContextType == CONTEXT_OPENGL4) {
            return new reboot_kernel_opengl::VertexArray();
        }
        return nullptr;
    }


    reboot_kernel::IndexBuffer *Context::createIBO(unsigned *data, unsigned count) {
        if (m_ContextType == CONTEXT_OPENGL4) {
            return new reboot_kernel_opengl::IndexBuffer(data, count);
        }
        return nullptr;
    }


    reboot_kernel::ShaderProgram* Context::createShader(){
        if (m_ContextType == CONTEXT_OPENGL4) {
            return new reboot_kernel_opengl::ShaderProgram();
        }
        return nullptr;
    }
}
