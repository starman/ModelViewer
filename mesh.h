#ifndef MESH_CLASS_H
#define MESH_CLASS_H

#include <string>

#include "vertex_array_object.h"
#include "element_buffer_object.h"
#include "camera.h"
#include "texture.h"

class Mesh
{
public:
	std::vector <Vertex> vertices;
	std::vector <GLuint> indices;
	std::vector <Texture> textures;
	VertexArrayObject vertexArrayObject;

	Mesh();
	Mesh(std::vector <Vertex>& vertices, std::vector <GLuint>& indices, std::vector <Texture>& textures);

	void draw(Shader& shader, Camera& camera);
};
#endif
