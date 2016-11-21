#pragma once

#include <preprocessor.h>
#include <kernel/context/buffer.h>


namespace reboot_kernel {
    class REBOOT_API IndexBuffer : public Buffer {
    protected:
        unsigned *m_Data;
    public:
        IndexBuffer(unsigned *data, unsigned count) : Buffer(count), m_Data(data) {}

        unsigned *getData() {
            return m_Data;
        }

        virtual void create() override {}
        virtual void clean() override {}
        virtual void bind() override {}

        virtual void unbind() override {}

    };
}