#pragma once

#include <preprocessor.h>
#include <kernel/context/buffer.h>
#include <vector>

namespace reboot_kernel{
    class REBOOT_API VertexBuffer{
    protected:
        std::vector<Buffer*> m_Buffers;
        unsigned m_BufferID;
    public:
        VertexBuffer(){}
        virtual ~VertexBuffer(){}
        virtual void addBuffer(Buffer* buffer, unsigned index){}
        virtual void bind() {}
        virtual void unbind() {}
    };
}