#include "mesh.h"

Mesh::Mesh()
{
	
}

Mesh::Mesh(std::vector <Vertex>& vertices, std::vector <GLuint>& indices, std::vector <Texture>& textures)
{
	Mesh::vertices = vertices;
	Mesh::indices = indices;
	Mesh::textures = textures;

	vertexArrayObject.bind();
	VertexBufferObject vertexBufferObject(vertices);
	ElementBufferObject elementBufferObject(indices);

	vertexArrayObject.linkAttrib(vertexBufferObject, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)0);
	vertexArrayObject.linkAttrib(vertexBufferObject, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)(3 * sizeof(float)));
	vertexArrayObject.linkAttrib(vertexBufferObject, 2, 2, GL_FLOAT, sizeof(Vertex), (void*)(6 * sizeof(float)));

	vertexArrayObject.unbind();
	vertexBufferObject.unbind();
	elementBufferObject.unbind();
}


void Mesh::draw(Shader& shader, Camera& camera)
{
	shader.activate();
	vertexArrayObject.bind();

	unsigned int texCount = 0;

	for (unsigned int i = 0; i < textures.size(); i++)
	{
		std::string num;
		num = std::to_string(texCount++);

		textures[i].texUnit(shader, ("texture" + num).c_str(), i);
		textures[i].bind();
	}
	glUniform3f(glGetUniformLocation(shader.id, "uCamPos"), camera.position.x, camera.position.y, camera.position.z);
	camera.matrix(shader, "uCamMatrix");

	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
}