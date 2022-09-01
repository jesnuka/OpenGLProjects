#version 330 core

in vec3 vertexColor;
in vec4 vertexPosition;
in vec2 texCoord;
out vec4 FragColor;

uniform vec3 uniColor;
uniform sampler2D uniTexture1;
uniform sampler2D uniTexture2;

void main()
{
	//FragColor = vec4(vertexColor,1.0);
	//FragColor = vertexPosition;
	//FragColor = texture(uniTexture, texCoord) * vertexPosition;
	//FragColor = texture(uniTexture1, texCoord) * vec4(vertexColor, 1.0);
	FragColor = mix(texture(uniTexture1, texCoord), 
					texture(uniTexture2, texCoord) * vec4(vertexColor, 1.0), 0.3);
	//FragColor = vec4(vertexColor, 1.0);
}