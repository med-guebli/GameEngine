#include "Madness/window.h";


void mouseMove(Madness::Window* window, double x, double y) {
	Madness::Triangle t2;
	t2.SetA(Madness::Vec(-0.1 / x, -0.1 / y, 0.0f, 1.0f));
	t2.SetB(Madness::Vec(0.1 / x, -0.1 / y, 0.0f, 1.0f));
	t2.SetC(Madness::Vec(0.2 / x, 0.1 / y, 0.0f, 1.0f));
	t2.SetColor(Madness::Vec(0.5, 0.8, 0.2, 0));
	window->Add(t2);
}

int main(void)
{
	/*int shaderUniformColorLocation = glGetUniformLocation(program, "uColor");*/
	Madness::WindowSettings settings("The title", 1080, 768);
	Madness::Window window = Madness::Window::Create(settings);

	window.OnMouseMove(window, mouseMove);

	while (window.IsRunning())
	{
	}

	return 0;
}