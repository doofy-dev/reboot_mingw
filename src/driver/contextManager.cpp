#include <driver/contextManager.h>
#include <adapter/canvas/canvas.h>
#include <adapter/canvas/window.h>
#include <adapter/context/openGL/oglShader.h>

namespace reboot_driver {
    ContextManager::ContextManager(short contextType, short canvasType)
            : m_ContextType(contextType) {
        switch (canvasType) {
            case CANVAS_FRAME:
                break;
            case CANVAS_GLFW:
            default:
                m_Canvas = new reboot_adapter::Window();
                break;
        }
    }

    bool ContextManager::closed() {
        return m_Canvas->closed();
    }

    void ContextManager::update() {
        m_Canvas->update();
    }
}
