#pragma once

#include <preprocessor.h>
#include <kernel/context/buffer.h>


namespace reboot_kernel {
    class REBOOT_API ComponentBuffer : public Buffer {
    protected:
        float *m_Data;
        unsigned m_ComponentCount;
    public:
        ComponentBuffer(float *data, unsigned count, unsigned componentCount) :
                Buffer(count), m_Data(data), m_ComponentCount(componentCount) {}


        virtual void create() override {}
        virtual void clean() override {}
        virtual void bind() override {}

        virtual void unbind() override {}

    };
}