#pragma once

#include <preprocessor.h>
#include <kernel/context/buffer.h>
#include <kernel/context/componentBuffer.h>


namespace reboot_kernel_opengl {
    class REBOOT_API ComponentBuffer : public reboot_kernel::ComponentBuffer {
    protected:
        float *m_Data;
        unsigned m_ComponentCount;
    public:
        ComponentBuffer(float *data, unsigned count, unsigned componentCount) :
                reboot_kernel::ComponentBuffer(data, count, componentCount){}


        virtual void create() override {}
        virtual void clean() override {}
        virtual void bind() override {}

        virtual void unbind() override {}

    };
}