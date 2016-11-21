#pragma once

#include <preprocessor.h>

namespace reboot_kernel
{

//Abstract class for the buffers
	class REBOOT_API Buffer
	{
	protected:
		unsigned m_BufferID;
		unsigned m_Count;

    public:
        Buffer(unsigned count):m_BufferID(0),m_ComponentCount(count){
            create();
        }

        virtual ~Buffer(){
            clean();
        }
        virtual void create(){}
		virtual void bind(){}
		virtual void unbind(){}
		virtual void clean(){}

		inline unsigned int getCount() const { return m_ComponentCount; }
	};
}