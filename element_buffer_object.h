#ifndef ELEMENT_BUFFER_OBJECT_CLASS_H
#define ELEMENT_BUFFER_OBJECT_CLASS_H

#include <glad/glad.h>
#include <vector>

class ElementBufferObject
{
public:
	GLuint id;
	
	ElementBufferObject(std::vector<GLuint>& indices);

	void bind();
	void unbind();
	void cleanup();
};

#endif
