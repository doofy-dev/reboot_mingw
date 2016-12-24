#include <preprocessor.h>
#include <kernel/context/arrayBuffer.h>

#pragma once
namespace reboot_kernel_opengl{
    class REBOOT_API ArrayBuffer : public reboot_kernel::ArrayBuffer{
    public:
        ArrayBuffer(float *data, unsigned int count):reboot_kernel::ArrayBuffer(data,count){}

        void create() override;
        void clean() override;
        void bind() override;
        void unbind() override;
    };
}