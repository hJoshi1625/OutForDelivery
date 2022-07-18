#pragma once

#include <glad/glad.h>
#include <glfw/glfw3.h>

class Window
{
public:
	Window(float width, float height, const char* title);
	~Window();

	void processEvents();
	
	void update();

public:
	float m_width;
	float m_height;
	
	float inline topEdge() const { return ((m_height / 2) - 1); }
	float inline rightEdge() const { return ((m_width / 2) - 1); }
	float inline bottomEdge() const { return -(m_height / 2); }
	float inline leftEdge() const { return -(m_width / 2); }

	GLFWwindow* window;
};
