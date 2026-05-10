#include "shader.h"
#include "../wrapper/check.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

Shader::Shader(const char* vertexPath, const char* fragmentPath) {
	//用于Shader的代码
	std::string vertexCode;
	std::string fragmentCode;
	//Shader的文件
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;
	//遇到问题抛出异常
	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try {
		//打开文件
		vShaderFile.open(vertexPath);
		fShaderFile.open(fragmentPath);
		//将文件中的数据载入到stream中
		std::stringstream vShaderStream, fShaderStream;
		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();
		//关闭文件
		vShaderFile.close();
		fShaderFile.close();
		//将stream转化为code  最终目标就是code
		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
	}

	catch(std::ifstream::failure& e){
		std::cout << "ERROR : Shader file failure..." << e.what() << std::endl;
	}

	const char* vertexShaderSource = vertexCode.c_str();
	const char* fragmentShaderSource = fragmentCode.c_str();
	//创建Shader程序
	GLuint vertex, fragment;
	vertex = glCreateShader(GL_VERTEX_SHADER);
	fragment = glCreateShader(GL_FRAGMENT_SHADER);

	//向Shader中添加代码
	glShaderSource(vertex, 1, &vertexShaderSource, NULL);
	glShaderSource(fragment, 1, &fragmentShaderSource, NULL);

	
	//编译
	glCompileShader(vertex);
	checkShaderError(vertex, "COMPILE");

	glCompileShader(fragment);
	checkShaderError(fragment, "COMPILE");

	//program  1. 创建program  2.  attach Shader   3. link program

	mProgram = glCreateProgram();
	glAttachShader(mProgram, vertex);
	glAttachShader(mProgram, fragment);
	glLinkProgram(mProgram);
	//检查
	checkShaderError(mProgram, "LINK");
	//清理
	glDeleteShader(vertex);
	glDeleteShader(fragment);

}

Shader::~Shader() {

}

void Shader::begin() {
	GL_CALL(glUseProgram(mProgram));

}

void Shader::end() {
	GL_CALL(glUseProgram(0));

}

void Shader::checkShaderError(GLuint target, std::string type) {
	char infolog[1024];
	int success = 0;
	if (type == "COMPILE") {
		glGetShaderiv(target, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(target, 1024, NULL, infolog);
			std::cout << "ERROR COMPILE --VERSION/FRAGMENT: \n" << infolog << std::endl;
		}
	}
	else if(type=="LINK") {
		glGetProgramiv(target, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(target, 1024, NULL, infolog);
			std::cout << "ERROR LINK PROGRAM: \n" << infolog << std::endl;
		}
	}
	else {
		std::cout << "ERROR: Check Shader errors Type is wrong..." << std::endl;
	}
}

void Shader::setFloat(const std::string& Name, float Value) {
	GLint location = glGetUniformLocation(mProgram, Name.c_str());
	
	glUniform1f(location, Value);
}

void Shader::setVec3(const std::string& name, float x, float y, float z) {
	GLint location = glGetUniformLocation(mProgram, name.c_str());
	GL_CALL(glUniform3f(location, x, y, z));
}

void Shader::setVec3fv(const std::string& name, const float* vecColor) {
	GLint location = glGetUniformLocation(mProgram, name.c_str());
	glUniform3fv(location, 1, vecColor);

}

void Shader::setInt(const std::string& name, int value) {
	GLint location = GL_CALL(glGetUniformLocation(mProgram, name.c_str()));
	glUniform1i(location, value);
}

void Shader::setMatrix4x4(const std::string& name, glm::mat4 value) {
	GLint location = glGetUniformLocation(mProgram, name.c_str());
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
}
