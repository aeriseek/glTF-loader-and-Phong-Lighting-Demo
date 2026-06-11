#pragma once

#include <glad/glad.h>
#include <string_view>
#include <string>


std::string getFileContent(const char* fileName);

class Shader
{
public:
	GLuint ID;
	Shader(const char* vertexFile, const char* fragmentFile);

	void Activate();
	void Delete();
};