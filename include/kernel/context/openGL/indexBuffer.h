#pragma once

#include "../indexBuffer.h"

namespace reboot_kernel_opengl{
    class IndexBuffer : public reboot_kernel::IndexBuffer{
    public:
        IndexBuffer(unsigned int *data, unsigned int count):reboot_kernel::IndexBuffer(data,count){
            create(data,count);
        }
~IndexBuffer();
        void create(unsigned *data, unsigned count);
        void bind() override;
        void unbind() override;
    };
}