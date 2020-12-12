#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>

#include "WindowSettings.h"
#include "Triangle.h"
#include "Shader.h"
#include "Program.h"
#include "VertexArray.h"
#include "Common.h"

namespace Madness {

	const std::string VERTEX_SHADER_FILENAME = "./res/shaders/vertex.shader";
	const std::string FRAGMENT_SHADER_FILENAME = "./res/shaders/fragment.shader";

	class Window {

		typedef void(*MouseMoveCallback)(Window* window, double x, double y);

	public:

		static Window Create(WindowSettings& settings);
		static void OnMouseMove(Window& window, MouseMoveCallback callback);
		static Window* window;
		static MouseMoveCallback callback;


		bool IsRunning();
		void Add(Madness::Shape& shape);

		//static void __GLFWMouseMoveCallback(GLFWwindow* window, double x, double y) {
		//	//m_onMouseMove(&Window::window, x, y);
		//}

	private:

		Window(WindowSettings& settings);
		void InitWindow();
		void InitGLWF();
		void InitSettings();
		void InitShaders();
		void Render();

		int m_width, m_height;
		std::string m_title;

		GLFWwindow* m_glfWindow;
		std::vector<Madness::Shape*> m_shapes;

		Madness::Shader m_vertexShader;
		Madness::Shader m_fragmentShader;

		GLuint m_vao, m_vboPosition, m_vboColor;
	};
}