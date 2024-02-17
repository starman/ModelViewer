#include "vertex_array_object.h"

VertexArrayObject::VertexArrayObject()
{
	glGenVertexArrays(1, &id);
}

void VertexArrayObject::linkAttrib(VertexBufferObject& vertexBufferObject, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset)
{
	vertexBufferObject.bind();
	glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
	glEnableVertexAttribArray(layout);
	vertexBufferObject.unbind();
}

void VertexArrayObject::bind()
{
	glBindVertexArray(id);
}

void VertexArrayObject::unbind()
{
	glBindVertexArray(0);
}

void VertexArrayObject::cleanup()
{
	glDeleteVertexArrays(1, &id);
}