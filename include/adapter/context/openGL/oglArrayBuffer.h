#include <preprocessor.h>
#include <adapter/context/arrayBuffer.h>

#pragma once
namespace reboot_adapter{
    class REBOOT_API OGLArrayBuffer : public ArrayBuffer{
    public:
        OGLArrayBuffer(float* data, unsigned count):ArrayBuffer(data,count){}
        void create() override;
        void clean() override;
        void bind() override;
        void unbind() override;
    };
}