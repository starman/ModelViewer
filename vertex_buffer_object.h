#ifndef VERTEX_BUFFER_OBJECT_CLASS_H
#define VERTEX_BUFFER_OBJECT_CLASS_H

#include <glm/glm.hpp>
#include <glad/glad.h>
#include <vector>

struct Vertex
{
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 texCoords;
};

class VertexBufferObject
{
public:
	GLuint id;

	VertexBufferObject(std::vector<Vertex>& vertices);

	void bind();
	void unbind();
	void cleanup();
};

#endif
