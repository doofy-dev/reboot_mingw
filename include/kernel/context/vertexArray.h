#pragma once

#include <preprocessor.h>
#include <kernel/context/buffer.h>
#include <vector>

namespace reboot_kernel{
    class REBOOT_API VertexArray{
    protected:
        std::vector<Buffer*> m_Buffers;
        unsigned m_BufferID;
    public:
        VertexArray():Buffer() {}
        virtual ~VertexArray(){}
        virtual void addBuffer(Buffer* buffer, unsigned index){}
        virtual void bind() {}
        virtual void unbind() {}
    };
}