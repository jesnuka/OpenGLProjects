#pragma once

// Resize the window
void FramebufferSizeCallback(GLFWwindow* window, int width, int height);

// Process input inside the window
void ProcessInput(GLFWwindow* window);

// Triangle NDC, with Z being zero
float vertices[] = 
{
-0.5f, -0.5f, 0.0f,
0.5f, -0.5f, 0.0f,
0.0f, 0.5f, 0.0f
};
