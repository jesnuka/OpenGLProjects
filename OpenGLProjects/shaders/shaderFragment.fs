#version 330 core

out vec4 FragColor;
in vec3 vertexColor;
in vec4 vertexPosition;
uniform vec4 uniColor;

void main()
{
	//FragColor = vec4(vertexColor,1.0);
	FragColor = vertexPosition;
}