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

    reboot_kernel::Buffer *Context::createBuffer(unsigned count) {
        if (m_ContextType == CONTEXT_OPENGL4) {
            using namespace reboot_kernel_opengl;
            return new reboot_kernel::Buffer(count);
        }
        return nullptr;
    }

    reboot_kernel::Buffer *Context::createFBO() {
        return nullptr;
    }

    reboot_kernel::VertexBuffer *Context::createVBO() {
        if (m_ContextType == CONTEXT_OPENGL4) {
            using namespace reboot_kernel_opengl;
            return new reboot_kernel::VertexBuffer();
        }
        return nullptr;
    }

    reboot_kernel::ArrayBuffer *Context::createArrayBuffer(float *data, unsigned count) {
        if (m_ContextType == CONTEXT_OPENGL4) {
            using namespace reboot_kernel_opengl;
            return new reboot_kernel::ArrayBuffer(data, count);
        }
        return nullptr;
    }

    reboot_kernel::IndexBuffer *Context::createIBO(unsigned *data, unsigned count) {
        if (m_ContextType == CONTEXT_OPENGL4) {
            using namespace reboot_kernel_opengl;
            return new reboot_kernel::IndexBuffer(data, count);
        }
        return nullptr;
    }
    reboot_kernel::ComponentBuffer *Context::createComponentBuffer(float *data, unsigned count, unsigned componentCount) {
        if (m_ContextType == CONTEXT_OPENGL4) {
            using namespace reboot_kernel_opengl;
            return new reboot_kernel::ComponentBuffer(data, count,componentCount);
        }
        return nullptr;
    }
}
