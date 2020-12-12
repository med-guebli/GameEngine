#include "Madness/window.h"
#include <algorithm>

namespace Madness {

	Window* Window::window = nullptr;
	Window::MouseMoveCallback Window::callback = 0;

	Window::Window(WindowSettings& settings) :
		m_vertexShader(Madness::VERTEX_SHADER_FILENAME, GL_VERTEX_SHADER),
		m_fragmentShader(Madness::FRAGMENT_SHADER_FILENAME, GL_FRAGMENT_SHADER)
	{
		this->m_title = settings.GetTitle();
		this->m_width = settings.GetWidth();
		this->m_height = settings.GetHeight();
		this->m_glfWindow = nullptr;

		this->m_vao = 0;
		this->m_vboPosition = 0;
		this->m_vboColor = 0;

		this->InitWindow();
	}

	//Window Window::Create(WindowSettings& settings)
	//{

	//}

	void Window::InitWindow() {
		this->InitGLWF();
		this->InitSettings();
		this->InitShaders();
	}

	bool Window::IsRunning() {
		if (!glfwWindowShouldClose(this->m_glfWindow)) {
			glClear(GL_COLOR_BUFFER_BIT);

			this->Render();

			/* Swap front and back buffers */
			glfwSwapBuffers(this->m_glfWindow);

			/* Poll for and process events */
			glfwPollEvents();

			return true;
		}
		else {
			glfwTerminate();

			return false;
		}
	}

	void Window::Add(Madness::Shape& shape) {
		this->m_shapes.push_back(&shape);
	}

	Window Window::Create(WindowSettings& settings)
	{
		return Window(settings);
	}

	void Window::OnMouseMove(Window& w, MouseMoveCallback callback)
	{
		Window::window = &w;
		Window::callback = callback;

		glfwSetCursorPosCallback(w.m_glfWindow, [](GLFWwindow * glfwWindow, double x, double y) {
			Window::callback(Window::window, x, y);
		});
	}

	void Window::InitGLWF() {
		/* Initialize the library */
		if (!glfwInit())
			return;

		/* Create a windowed mode window and its OpenGL context */
		this->m_glfWindow = glfwCreateWindow(this->m_width, this->m_height, this->m_title.c_str(), NULL, NULL);
		if (!this->m_glfWindow)
		{
			glfwTerminate();
			return;
		}

		/* Make the window's context current */
		glfwMakeContextCurrent(this->m_glfWindow);

		if (glewInit() != GLEW_OK) {
			std::cout << "Something went wrong !" << std::endl;
		}
	}

	void Window::InitSettings() {
		glViewport(0, 0, this->m_width, this->m_height);
		glfwSwapInterval(1);
		//glfwSetFramebufferSizeCallback(this->_window, framebuffer_size_callback);
		glClearColor(0.2, 0.4, 0.7, 1);
	}

	void Window::InitShaders() {
		this->m_vertexShader.Init();
		this->m_fragmentShader.Init();
	}

	void Window::Render() {
		for (size_t i = 0; i < this->m_shapes.size(); i++)
		{
			Madness::Shape* shape = this->m_shapes.at(i);
			std::vector<Madness::Vec> vertices = shape->GetVertices();
			std::vector<Madness::Vec> colors = shape->GetColors();

			VertexArray vertexArray;

			VertexBuffer positionBuffer(vertices, 0, GL_ARRAY_BUFFER, GL_STATIC_DRAW, GL_FALSE);
			VertexBuffer colorBuffer(colors, 1, GL_ARRAY_BUFFER, GL_STATIC_DRAW, GL_FALSE);

			vertexArray.Add(positionBuffer);
			vertexArray.Add(colorBuffer);

			vertexArray.Bind();

			// Program creation
			Program program = Program::Create(this->m_vertexShader.CreateShader(), this->m_fragmentShader.CreateShader());

			program.Use();

			glDrawArrays(GL_POLYGON, 0, vertices.size());

			program.Delete();

			vertexArray.Unbind();
		}
	}
}