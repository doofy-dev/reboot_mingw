#pragma once
#include "../../preprocessor.h"
#include "canvas.h"

typedef struct GLFWwindow GLFWwindow;
namespace reboot_kernel
{
	class REBOOT_API Window: public Canvas
	{
	private:
		GLFWwindow *m_Window;
	public:
		Window();
		~Window();
		bool create() override;
		void setTitle(char *title) override;
		bool closed() override;
		void update() override;
		void resize(int widht, int height, Canvas *canvas) override;
		void setFullScreen(bool isFullScreen) override;
		void setCursor(bool enabled) override;
		void window_resize(GLFWwindow *window, int width, int height);
		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
	private:
		bool prepare();
	};
}
