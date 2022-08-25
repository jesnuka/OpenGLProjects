#pragma once

int drawmode = 1;

// Resize the window
void framebufferSizeCallback(GLFWwindow* window, int width, int height);

// Process input inside the window
void processInput(GLFWwindow* window);
void keyCallback(GLFWwindow* window);

// Triangle NDC, with Z being zero
float triangle[] = 
{
-0.5f, -0.5f, 0.0f,
0.5f, -0.5f, 0.0f,
0.0f, 0.5f, 0.0f
};

// Rectangle NDC, with Z being zero
float vertices[] =
{
	0.5f, 0.5f, 0.0f, // top right
	0.5f, -0.5f, 0.0f, // bottom right
	-0.5f, -0.5f, 0.0f, // bottom left
	-0.5f, 0.5f, 0.0f // top left
};

// Unique vertices used by an Element Buffer Object to draw a triangle using indiced vertices from the rectangle
unsigned int indices[]
{
	0, 1, 3, // First triangle
	1, 2, 3 // Second triangle
};
