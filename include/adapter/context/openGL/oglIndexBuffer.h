#pragma once

#include <preprocessor.h>

#include <adapter/context/indexBuffer.h>

namespace reboot_adapter{
    class REBOOT_API OGLIndexBuffer : public IndexBuffer{
    public:
        OGLIndexBuffer(unsigned *data, unsigned count):IndexBuffer(data, count){}
        ~OGLIndexBuffer();
    protected:
        void create() override;

        void bind() override;

        void unbind() override;

    };
}