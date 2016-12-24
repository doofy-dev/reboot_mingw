#pragma once

#include <preprocessor.h>

#include <kernel/context/indexBuffer.h>

namespace reboot_kernel_opengl{
    class REBOOT_API IndexBuffer : public reboot_kernel::IndexBuffer{
    public:
        IndexBuffer(unsigned *data, unsigned count):reboot_kernel::IndexBuffer(data, count){}
    protected:
        void create() override;
        void clean() override;
        void bind() override;

        void unbind() override;

    };
}