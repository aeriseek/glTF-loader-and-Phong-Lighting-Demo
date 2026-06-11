#include "Shader.h"
#include <fstream>


std::string getFileContent(const char* fileName)
{
	std::ifstream in(fileName, std::ios::binary);
	if (!in) throw (errno);
	std::string content;
	in.seekg(0, std::ios::end);
	content.resize(in.tellg());
	in.seekg(0, std::ios::beg);
	in.read(&content[0], content.size());
	in.close();
	return content;
}


Shader::Shader(const char* vertexFile, const char* fragmentFile)
{
	std::string vertexCode = getFileContent(vertexFile);
	std::string fragmentCode = getFileContent(fragmentFile);

	const char* vertexSource = vertexCode.c_str();
	const char* fragmentSource = fragmentCode.c_str();

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vertexShader, 1, &vertexSource, nullptr);
	glShaderSource(fragmentShader, 1, &fragmentSource, nullptr);

	glCompileShader(vertexShader);
	glCompileShader(fragmentShader);

	ID = glCreateProgram();
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);

	glLinkProgram(ID);


	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

}

void Shader::Activate()
{
	glUseProgram(ID);

}
void Shader::Delete()
{
	glDeleteProgram(ID);
}
