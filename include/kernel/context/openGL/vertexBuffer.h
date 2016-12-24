#pragma once

#include <vector>
#include <preprocessor.h>
#include <kernel/context/vertexBuffer.h>

namespace reboot_kernel_opengl{
    class REBOOT_API VertexBuffer:public reboot_kernel::VertexBuffer{

    public:
        VertexBuffer();
        ~VertexBuffer();
        virtual void addBuffer(reboot_kernel::Buffer* buffer, unsigned index);
        virtual void bind() override;
        virtual void unbind() override;
    };
}