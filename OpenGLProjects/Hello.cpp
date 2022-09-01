#include "Hello.h"

// Store the Vertex Shader GLSL as a const C string
/*const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec3 aColor;\n"
"out vec3 vertexColor;\n"
"void main()\n"
"{\n"
" gl_Position = vec4(aPos, 1.0);\n"
" vertexColor = aColor;\n"
"}\0";*/

/*// Store the Fragment Shaders GLSL as a const C string
const char* fragmentShaderSource1 = "#version 330 core\n"
"out vec4 FragColor;\n"
"in vec3 vertexColor;\n"
"uniform vec4 uniColor;\n"
"void main()\n"
"{\n"
"	FragColor = vec4(vertexColor,1.0);\n"
"}\0";*/

/*const char* fragmentShaderSource2 = "#version 330 core\n"
"out vec4 FragColor;\n"
"in vec4 vertexColor;\n"
"void main()\n"
"{\n"
"	FragColor = vertexColor;\n"
"}\0";*/

void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
	// Escape closes the window
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);


}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	// M button toggles draw mode
	if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS)
		drawmode = (drawmode + 1) % 2;
}

int main()
{
	// Initialize GLFW
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	// Create the window object
	GLFWwindow* window = glfwCreateWindow(800, 600, "Learning OpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW Window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	// Set Window resizing function callback
	glViewport(0, 0, 800, 600);
	glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
	glfwSetKeyCallback(window, keyCallback);

	Shader shaderProgram("shaders/shaderVertex.vs", "shaders/shaderFragment.fs");

	
	unsigned int textureID;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	// Set the texture filtering and wrapping options
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	// Load the data
	int width, height, nrChannels;
	const char* fileName = "woodPlanks.jpg";
	unsigned char* textureData = stbi_load(fileName, &width, &height,
		&nrChannels, 0);

	// If data was loaded successfully, generate the texture and it's mipmaps
	if (textureData)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, textureData);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load the texture: "<< fileName << std::endl;
	}

	// Free the image memory once it has been used
	stbi_image_free(textureData);

	// Create the vertex array objects
	unsigned int VAOs[2];
	glGenVertexArrays(2, VAOs);

	// Create vertex buffer objects
	unsigned int VBOs[2];
	glGenBuffers(2, VBOs);

	// Create and bind an Element Buffer Object
	unsigned int EBO;
	glGenBuffers(1, &EBO);

	// Bind vertex array object 1
	glBindVertexArray(VAOs[0]);
	// Copy vertices array in a buffer for OpenGL to use
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
	// Copy vertex data to buffer's memory as GL_STATIC_DRAW
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBufferData(GL_ARRAY_BUFFER, sizeof(rectangle), rectangle, GL_STATIC_DRAW);

	// Set the vertex attribute pointers
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// Color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// Texture attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	// Bind vertex array object 2
	/*lBindVertexArray(VAOs[1]);
	// Copy vertices array in a buffer for OpenGL to use
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
	// Copy vertex data to buffer's memory as GL_STATIC_DRAW
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBufferData(GL_ARRAY_BUFFER, sizeof(rectangle), rectangle, GL_STATIC_DRAW);

	// Set the vertex attribute pointers
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);*/


	// Copy index array to an element buffer for OpenGL to use
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Create the vertex shader, attach the source to it and compile it
	/*unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	// Check for errors
	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	// Create the fragment shader, attach the source to it and compile it
	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource1, NULL);
	glCompileShader(fragmentShader);

	// Check for errors
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT:COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	/*unsigned int fragmentShader2;
	fragmentShader2 = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader2, 1, &fragmentShaderSource2, NULL);
	glCompileShader(fragmentShader2); 

	// Check for errors
	glGetShaderiv(fragmentShader2, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader2, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT:COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	
	// Create a shader program for linking the vertex and fragment shaders
	//unsigned int shaderProgram, shaderProgram2;
	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();
	//shaderProgram2 = glCreateProgram();
	// Attach the shaders to the program and link them
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram); 
//	glAttachShader(shaderProgram2, vertexShader);
	//glAttachShader(shaderProgram2, fragmentShader2);
	//glLinkProgram(shaderProgram2);

	// TODO: Combine error checking
	// Check for errors
	glGetProgramiv(shaderProgram, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::PROGRAM::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	// Check for errors
	glGetProgramiv(shaderProgram2, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(shaderProgram2, 512, NULL, infoLog);
		std::cout << "ERROR::PROGRAM::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	// Delete shaders as they are not needed anymore after linking
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader); */
	//glDeleteShader(fragmentShader2);

	switch (drawmode)
	{
	case 0:
		// Wireframe Mode
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		break;
	case 1:
		// Fill Mode
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		break;
	default:
		break;
	}

		// Render Loop, one loop is a frame
		while (!glfwWindowShouldClose(window))
		{
			// Get input
			processInput(window);

			// Clear the screen using ClearColor
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);


			// Activate the shaderProgram to be used by later shader and rendering calls 
			shaderProgram.use();

			// Update Uniform Color
			float timeVal = glfwGetTime();
			float greenVal = sin(timeVal) / 2.0f + 0.5f;
			//int vertexColorLoc = glGetUniformLocation(shaderProgram, "uniColor");
		//	glUniform4f(vertexColorLoc, 0.0f, greenVal, 0.0f, 1.0f);
			shaderProgram.setFloat("uniColor", greenVal);
			//shaderProgram.setFloat("offsetVal", 0.5f);

		//	glDrawArrays(GL_TRIANGLES, 0, 3);


		//	glUseProgram(shaderProgram2);
		//	glBindVertexArray(VAOs[1]);
			//glDrawArrays(GL_TRIANGLES, 0, 3);

			glBindTexture(GL_TEXTURE_2D, textureID);
			glBindVertexArray(VAOs[0]);

			// Draw the objects using an Element Array Buffer, which is stored binded in the VAO
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
			glBindVertexArray(0);

			// Check if any events are triggered, to update the window and call callback functions
			glfwPollEvents();
			// Swap the color buffer to show output
			glfwSwapBuffers(window);
		}

	glfwTerminate();
	return 0;
}