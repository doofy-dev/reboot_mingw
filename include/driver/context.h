#pragma once

#include "../preprocessor.h"
#include <vector>
#include <afxres.h>
#include "../kernel/canvas/canvas.h"
#include "../kernel/context/shaderProgram.h"

#include <kernel/opengl.h>


namespace reboot_driver {
    class REBOOT_API Context {
    public:
        static Context *current;
    private:
        BYTE m_ContextType;
        BYTE m_CanvastType;
    public:
        reboot_kernel::Canvas *m_Canvas;
        std::vector<reboot_kernel::ShaderProgram *> m_Programs;

    public:
        Context(BYTE contextType, BYTE canvasType);

        void makeCurrent() { current = this; }

        reboot_kernel::Buffer *createBuffer(float* data, unsigned count, unsigned componentCount);
        reboot_kernel::Buffer *createFBO();
        reboot_kernel::VertexArray *createVAO();
        reboot_kernel::IndexBuffer *createIBO(unsigned *data, unsigned count);
        reboot_kernel::ShaderProgram* createShader();
    };
}
