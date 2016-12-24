#include <kernel/canvas/window.h>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace reboot_kernel
{
	Window::Window():Canvas(), m_Window(nullptr)
	{
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	bool Window::prepare()
	{
		if (!glfwInit())
		{
			std::cout << "Failed to initialize GLFW!" << std::endl;
		}
		glfwWindowHint(GLFW_SAMPLES, 4); //antialiasing
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); //opengl major
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0); //opengl minor
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //use the newest OpenGL

		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
		if (!m_Window)
		{
			std::cout << "Failed to create GLFW window!" << std::endl;
			return false;
		}

        auto mousecallback = [](GLFWwindow* w, int a, int b, int c)
        {
            static_cast<Window*>(glfwGetWindowUserPointer(w))->mouse_button_callback(w,a,b,c);
        };
        auto keycallback = [](GLFWwindow* w, int a, int b, int c, int d)
        {
            static_cast<Window*>(glfwGetWindowUserPointer(w))->key_callback(w,a,b,c,d);
        };
        auto winresize = [](GLFWwindow* w, int a, int b)
        {
            static_cast<Window*>(glfwGetWindowUserPointer(w))->window_resize(w,a,b);
        };
        auto cursorcallback = [](GLFWwindow* w, double a, double b)
        {
            static_cast<Window*>(glfwGetWindowUserPointer(w))->cursor_position_callback(w,a,b);
        };
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, this);
		glfwSetWindowSizeCallback(m_Window, winresize);
		glfwSetKeyCallback(m_Window, keycallback);
		glfwSetMouseButtonCallback(m_Window, mousecallback);
		glfwSetCursorPosCallback(m_Window, cursorcallback);

		if (glewInit() != GLEW_OK)
		{
			std::cout << "Could not initialize GLFW!" << std::endl;
			return false;
		}
		return true;
	}

	bool Window::create()
	{
		if (!prepare())
		{
			glfwTerminate();
			return false;
		}
		return true;
	}

	void Window::setTitle(char* title)
	{
	}

	bool Window::closed()
	{
		return glfwWindowShouldClose(m_Window) == 1;
	}

	void Window::update()
	{
		auto error = glGetError();
		if (error != GL_NO_ERROR)
		{
			std::cout << "OpenGL error: " << error << std::endl;
		}
		glfwSwapBuffers(m_Window);
		glfwPollEvents();
		glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
	}

	void Window::resize(int width, int height, Canvas *canvas)
	{
        canvas->m_Width = width;
        canvas->m_Height = height;
        glViewport(0, 0, width, height);
	}

	void Window::setFullScreen(bool isFullScreen)
	{
	}

	void Window::setCursor(bool enabled)
	{
	}

	void Window::window_resize(GLFWwindow* window, int width, int height)
	{
		Window*	win = (Window*)glfwGetWindowUserPointer(window);
		std::cout << "Resize event" << std::endl;
        resize(width,height,win);
	}

	void Window::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Window*	win = (Window*)glfwGetWindowUserPointer(window);
		std::cout << "Key event" << std::endl;
	}

	void Window::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
	{
		Window*	win = (Window*)glfwGetWindowUserPointer(window);
		std::cout << "Click event" << std::endl;
	}

	void Window::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
	{
		Window*	win = (Window*)glfwGetWindowUserPointer(window);
		std::cout << "Cursor event" << std::endl;
	}
}
