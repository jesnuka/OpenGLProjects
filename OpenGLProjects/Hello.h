#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Shader.h"
#include "stb_image.h"


int drawmode = 1;

// Resize the window
void framebufferSizeCallback(GLFWwindow* window, int width, int height);

// Process input inside the window
void processInput(GLFWwindow* window);
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);

// Triangle NDC, with Z being zero
float triangle[] = 
{
-0.5f, -0.5f, 0.0f,
0.5f, -0.5f, 0.0f,
0.0f, 0.5f, 0.0f
};

float triangle1[] =
{
-0.75f, -0.5f, 0.0f, // Left
0.0f, -0.5f, 0.0f, // Right
-0.35f, 0.5f, 0.0f, // Top
};

float triangle2[] =
{
0.0f, -0.5f, 0.0f, // Left
0.75f, -0.5f, 0.0f, // Right
0.35f, 0.5f, 0.0f, // Top
};

// 2 Triangles NDC, with Z being zero
float triangles2[] =
{
-0.75f, -0.5f, 0.0f, // Left
0.0f, -0.5f, 0.0f, // Right
-0.35f, 0.5f, 0.0f, // Top

0.0f, -0.5f, 0.0f, // Left
0.75f, -0.5f, 0.0f, // Right
0.35f, 0.5f, 0.0f, // Top
};


// triangle
float vertices[] = {
	// positions // colors
	0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom right
	-0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // bottom left
	0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f // top
};

// Rectangle NDC, with Z being zero and with texture coordinates
float rectangle[] = {
	// positions // colors // texture coords
	0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // top right
	0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // bottom right
	-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
	-0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f // top left
};

// Unique vertices used by an Element Buffer Object to draw a triangle using indiced vertices from the rectangle
unsigned int indices[]
{
	0, 1, 3, // First triangle
	1, 2, 3 // Second triangle
};
