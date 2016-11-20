#include <preprocessor.h>
#include <adapter/context/buffer.h>

#pragma once
namespace reboot_adapter{
    class REBOOT_API OGLIndexBufferr : public Buffer{
    public:
        ~OGLIndexBufferr() override;
        void load(float* data, int count);
        void bind() override;
        void unbind() override;
    };
}