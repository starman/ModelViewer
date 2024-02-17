#include "element_buffer_object.h"

ElementBufferObject::ElementBufferObject(std::vector<GLuint>& indices)
{
	glGenBuffers(1, &id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);
}

void ElementBufferObject::bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
}

void ElementBufferObject::unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void ElementBufferObject::cleanup()
{
	glDeleteBuffers(1, &id);
}