#version 330 core

in vec3 vertexColor;
in vec4 vertexPosition;
in vec2 texCoord;
out vec4 FragColor;

uniform vec3 uniColor;
uniform sampler2D uniTexture;

void main()
{
	//FragColor = vec4(vertexColor,1.0);
	//FragColor = vertexPosition;
	//FragColor = texture(uniTexture, texCoord) * vertexPosition;
	FragColor = texture(uniTexture, texCoord) * vec4(vertexColor, 1.0);
	//FragColor = vec4(vertexColor, 1.0);
}