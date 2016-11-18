#pragma once

#include <preprocessor.h>
#include <adapter/context/buffer.h>
#include <vector>

namespace reboot_adapter{
    class REBOOT_API VertexArray : public Buffer{
    protected:
        std::vector<Buffer*> m_Buffers;

    public:
        VertexArray():Buffer() {}
        virtual ~VertexArray(){}
        virtual void addBuffer(Buffer* buffer, unsigned index){}
        virtual void bind() override{}
        virtual void unbind() override{}
    };
}