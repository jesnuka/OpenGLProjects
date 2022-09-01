#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

out vec3 vertexColor;
out vec4 vertexPosition;
out vec2 texCoord;
uniform float offsetVal;

void main()
{
 //gl_Position = vec4(aPos.x + offsetVal, -aPos.y, aPos.z, 1.0);
 gl_Position = vec4(aPos.x, -aPos.y, aPos.z, 1.0);
 vertexColor = aColor;
 vertexPosition = gl_Position;
 texCoord = aTexCoord;
}