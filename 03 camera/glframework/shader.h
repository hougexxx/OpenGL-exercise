#pragma once

#include "core.h"
#include <string>

class Shader {
public:
	Shader(const char* vertexPath, const char* fragmentPath);
	~Shader();

	//开始使用Shader
	void begin();

	//结束使用Shader
	void end();

	void setFloat(const std::string& Name, float Value);
	void setVec3(const std::string& name, float x, float y, float z);
	void setVec3fv(const std::string& name, const float* vecColor);
	void setInt(const std::string& name, int value);
	void setMatrix4x4(const std::string& name, glm::mat4 value);

private:
	void checkShaderError(GLuint target,std::string type);

public:
	GLuint mProgram = 0;

};