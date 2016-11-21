#pragma once

#include <preprocessor.h>
#include <adapter/context/buffer.h>

namespace reboot_adapter{
    class ArrayBuffer : public Buffer{
    protected:
        float* m_Data;
    public:
        ArrayBuffer(float* data, unsigned int count) :m_Data(data), Buffer(count) {}
        virtual void create() override {}
        virtual void bind() override {}
        virtual void unbind() override {}
        virtual void clean() override {}
    };
}