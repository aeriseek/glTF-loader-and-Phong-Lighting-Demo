#pragma once
#include <glad/glad.h>
#include <stb_image.h>


class Texture
{
public:
	GLuint ID;
	const char* type;
	GLuint unit;
	Texture(const char* imagePath, const char* type, GLuint slot);

	void Bind();
	void Unbind();
	void Delete();
};