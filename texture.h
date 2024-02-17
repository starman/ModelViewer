#ifndef TEXTURE_CLASS_H
#define TEXTURE_CLASS_H

#include <glad/glad.h>
#include <stb/stb_image.h>

#include "shader.h"

class Texture
{
public:
    GLuint id;
    std::string path;
    GLuint unit;

    Texture(std::string imagePath, GLuint slot);

    void texUnit(Shader& shader, std::string uniform, GLuint unit);
    void bind();
    void unbind();
    void cleanup();
};

#endif
