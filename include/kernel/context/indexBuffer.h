#pragma once

#include <preprocessor.h>
#include "buffer.h"

namespace reboot_kernel{
    class IndexBuffer:public Buffer{
    public:
        IndexBuffer(unsigned *data, unsigned count):Buffer(){
            create(data,count);
        };
        virtual void create(unsigned *data, unsigned count){}
        virtual void bind() override {}
        virtual void unbind() override {}
    };
}