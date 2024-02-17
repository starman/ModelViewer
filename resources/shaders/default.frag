#version 330 core

in vec3 fCrntPos;
in vec3 fNormal;
in vec2 fTexCoord;

out vec4 FragColor;

uniform vec3 uCamPos;
uniform sampler2D texture0;

void main()
{
	float ambient = 0.20f;

	vec3 viewDirection = normalize(uCamPos - fCrntPos);
	vec3 normal = normalize(fNormal);
	float diffuse = max(dot(normal, viewDirection), 0.0f);

	float specularLight = 0.50f;
	vec3 reflectionDirection = reflect(-viewDirection, normal);
	float specAmount = pow(max(dot(viewDirection, reflectionDirection), 0.0f), 8);
	float specular = specAmount * specularLight;

	FragColor = texture(texture0, fTexCoord) * (diffuse + ambient + specular);
}
