#pragma once

#include <vector>
#include <preprocessor.h>
#include <kernel/context/vertexArray.h>

namespace reboot_kernel{
    class REBOOT_API OGLVertexArray:public VertexArray{

    public:
        OGLVertexArray();
        ~OGLVertexArray();
        virtual void addBuffer(Buffer* buffer, unsigned index);
        virtual void bind() override;
        virtual void unbind() override;
    };
}