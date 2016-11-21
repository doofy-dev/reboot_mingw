#pragma once

#include <preprocessor.h>

namespace reboot_kernel
{
	class Canvas
	{
	protected:
		int m_Width, m_Height;
		char  *m_Title;
		bool m_FullScreen;
	public:
		Canvas();
		bool init(int width, int height, char *title);
		bool init(int width, int height) { return init(width, height, (char *)"Reboot engine"); }

		virtual ~Canvas() {}
		virtual bool create() { return false; }
		virtual void setTitle(char *title) { m_Title = title; }
		virtual void setCursor(bool enabled){}

		inline char& getTitle() const { return *m_Title; }
		inline int getWidth() const { return m_Width; }
		inline int getHeight() const { return m_Height; }
		inline bool isFullScreen() const { return m_FullScreen; }
		
		virtual bool closed() { return true; }
		virtual void update(){}
		virtual void resize(int widht, int height){}
		virtual void setFullScreen(bool isFullScreen){}
	};
}