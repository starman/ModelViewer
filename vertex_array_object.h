#ifndef VERTEX_ARRAY_OBJECT_CLASS_H
#define VERTEX_ARRAY_OBJECT_CLASS_H

#include <glad/glad.h>
#include "vertex_buffer_object.h"

class VertexArrayObject
{
public:
	GLuint id;

	VertexArrayObject();

	void linkAttrib(VertexBufferObject& vertexBufferObject, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);
	void bind();
	void unbind();
	void cleanup();
};

#endif