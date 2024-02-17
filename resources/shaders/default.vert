#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTex;

out vec3 fCrntPos;
out vec3 fNormal;
out vec2 fTexCoord;

uniform mat4 uCamMatrix;
uniform mat4 uModelMatrix;

void main()
{
	fCrntPos = vec3(uModelMatrix * vec4(aPos, 1.0f));

	fNormal = aNormal;
	fTexCoord = aTex;
	
	gl_Position = uCamMatrix * vec4(fCrntPos, 1.0);
}