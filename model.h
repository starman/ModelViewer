#ifndef MODEL_CLASS_H
#define MODEL_CLASS_H

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "mesh.h"

class Model
{
public:
	Model(std::string path);

	void draw(Shader& shader, Camera& camera);
	void loadModel(std::string path);
	void processNode(aiNode* node, const aiScene* scene);
	Mesh processMesh(aiMesh* mesh, const aiScene* scene);
	std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type);

private:
	std::string directory;
	std::vector<Mesh> meshes;
	std::vector<Texture> loadedTextures;
};
#endif