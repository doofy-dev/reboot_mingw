#pragma once

#include <preprocessor.h>

namespace reboot_kernel{
    class Buffer{
    public:
        unsigned m_ID=0;
        unsigned m_ComponentCount=0;
        unsigned m_Count=0;
        Buffer(float* data, unsigned count, unsigned componentCount):m_ComponentCount(componentCount){create(data,count);}
        Buffer(){create();}
        virtual void bind(){}
        virtual void unbind(){}
        virtual void create(){}
        virtual void create(float* data, unsigned count){}
    };
}
