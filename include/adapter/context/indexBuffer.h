#pragma once

#include <preprocessor.h>
#include <adapter/context/buffer.h>

namespace reboot_adapter {
    class REBOOT_API IndexBuffer : public Buffer {
    protected:
        unsigned *m_Data;
        unsigned m_Count;
    public:
        IndexBuffer(unsigned *data, unsigned count) : Buffer(), m_Data(data), m_Count(count) {
            create();
        }

        unsigned *getData() {
            return m_Data;
        }

    protected:
        virtual void create() {}

        virtual void bind() override {}

        virtual void unbind() override {}

    };
}