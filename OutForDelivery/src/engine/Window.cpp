#include "Window.h"

#include "Log.h"


Window::Window(float width, float height, const char* title = "Game")
	: m_width(width), m_height(height)
{
	Log log;
	if (!glfwInit())
	{
		log.error("Could not initialize GLFW.");
	}

	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

	glfwWindowHint(GLFW_RED_BITS, mode->redBits);
	glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
	glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
	glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);


	window = glfwCreateWindow(m_width, m_height, title, NULL, NULL);

	if (window == NULL)
	{
		log.error("Could not create window");
		glfwTerminate();
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int width, int height) {
		glViewport(0, 0, width, height);
		});


	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		log.error("Failed to initialize GLAD");
	}
}

Window::~Window()
{
	glfwTerminate();
}

void Window::processEvents()
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}



void Window::update()
{
	processEvents();

	glClearColor(0.011f, 0.223f, 0.423f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwSwapBuffers(window);
	glfwPollEvents();
}
