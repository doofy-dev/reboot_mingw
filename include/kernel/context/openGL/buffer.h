#pragma once

#include "../buffer.h"

namespace reboot_kernel_opengl{
    class Buffer: public reboot_kernel::Buffer{
    public:
        Buffer(float* data, unsigned count, unsigned componentCount):reboot_kernel::Buffer(data,count,m_ComponentCount){
            m_ComponentCount=componentCount;
            create(data,count);
        }
        ~Buffer();
        void bind() override;
        void unbind() override;
        void create(float* data, unsigned count) override;
    };
}