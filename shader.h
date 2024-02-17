#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>

std::string get_file_contents(std::string filePath);

class Shader
{
public:
	GLuint id;

	Shader(std::string vertexPath, std::string fragmentPath);

	void activate();
	void cleanup();
private:
	void compileErrors(unsigned int shader, std::string type);
};


#endif
