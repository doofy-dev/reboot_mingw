#pragma once

#include <preprocessor.h>

#include <kernel/context/indexBuffer.h>

namespace reboot_kernel{
    class REBOOT_API OGLIndexBuffer : public IndexBuffer{
    public:
        OGLIndexBuffer(unsigned *data, unsigned count):IndexBuffer(data, count){}
    protected:
        void create() override;
        void clean() override;
        void bind() override;

        void unbind() override;

    };
}