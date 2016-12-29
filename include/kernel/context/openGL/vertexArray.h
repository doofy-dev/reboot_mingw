#pragma once

#include "../vertexArray.h"
#include "buffer.h"

namespace reboot_kernel_opengl{
    class VertexArray: public reboot_kernel::VertexArray{
    public:
        VertexArray():reboot_kernel::VertexArray(){create();}
        ~VertexArray();
        void create() override;
        void addBuffer(reboot_kernel::Buffer *buffer, unsigned index) override;
        void bind() override;
        void unbind() override;
    };
}