#pragma once

#include <preprocessor.h>
#include "buffer.h"
#include <vector>

namespace reboot_kernel{
    class VertexArray:public Buffer{
    protected:
        std::vector<Buffer*> m_Buffers;
    public:
        VertexArray():Buffer(){create();}
        virtual void create() override {}
        virtual void addBuffer(Buffer *buffer, unsigned index){}
        virtual void bind() override {}
        virtual void unbind() override {}
    };
}