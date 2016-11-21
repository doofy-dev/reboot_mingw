#pragma once

#include <preprocessor.h>
#include <adapter/context/buffer.h>


//@TODO: Indexbuffer - Buffer talán nem jó leszármaztatva egymásból
//@TODO: Esetleg a buffer maga csak egy tároló legyen ID-vel, virtual bind/unbind-al (nem is rossz ötlet)
namespace reboot_adapter {
    class REBOOT_API IndexBuffer : public Buffer {
    protected:
        unsigned *m_Data;
    public:
        IndexBuffer(unsigned *data, unsigned count) : Buffer(count), m_Data(data) {}

        unsigned *getData() {
            return m_Data;
        }

        virtual void create() override {}

        virtual void bind() override {}

        virtual void unbind() override {}

    };
}