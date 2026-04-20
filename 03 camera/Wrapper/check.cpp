#include <iostream>
//glad 必须在GLFW之前引用    因为OpenGL库的引用顺序关系   !!!
#include <glad/glad.h>
#include <string>
#include <assert.h>
using namespace std;



void checkError() {
	bool error = false;
	GLenum errcode = glGetError();
	cout << "error code: " << errcode << endl;
	string errstr;

	if (errcode != GL_NO_ERROR) {
		switch (errcode) {
		case GL_INVALID_VALUE:errstr = "GL_INVALID_VALUE"; break;
		case GL_INVALID_OPERATION:errstr = "GL_INVALID_OPERATION"; break;
		case GL_OUT_OF_MEMORY:errstr = "GL_OUT_OF_MEMORY"; break;
		case GL_INVALID_ENUM:errstr = "GL_INVALID_ENUM"; break;
		default:
			errstr = "unkown error";
			break;
		}
		cout << "error string: " << errstr << endl;
		cout << "end ." << endl;
		error = true;
		assert(false);
	}

}
