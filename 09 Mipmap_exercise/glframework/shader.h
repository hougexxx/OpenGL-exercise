#pragma once

#include "core.h"
#include <string>

class shader {
public:
	shader(const char* vertexPath, const char* fragmentPath);
	~shader();

	//开始使用shader
	void begin();

	//结束使用shader
	void end();

	void setFloat(const std::string& Name, float Value);
	void setVec3(const std::string& name, float x, float y, float z);
	void setVec3fv(const std::string& name, const float* vecColor);
	void setInt(const std::string& name, int value);

private:
	void checkShaderError(GLuint target,std::string type);

public:
	GLuint mProgram = 0;

};