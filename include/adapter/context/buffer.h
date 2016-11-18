#pragma once

#include <preprocessor.h>

namespace reboot_adapter
{
	class REBOOT_API Buffer
	{
	protected:
		unsigned int m_BufferID;
		unsigned int m_ComponentCount;


    public:
        Buffer():m_BufferID(0),m_ComponentCount(0){}

        virtual ~Buffer(){}
		virtual void bind(){}
		virtual void unbind(){}
		virtual void clean(){}

		inline unsigned int getComponentCount() const { return m_ComponentCount; }
	};
}