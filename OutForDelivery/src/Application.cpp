#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "engine/Window.h"

int main()
{
	Window window(800, 600, "Out For Delivery");
	while (!glfwWindowShouldClose(window.window))
	{
		window.update();
	}
}