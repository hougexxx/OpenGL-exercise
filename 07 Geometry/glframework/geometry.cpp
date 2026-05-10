#include "geometry.h"

Geometry::Geometry() {

}

Geometry::~Geometry() {
	if (mVao != 0) {
		glDeleteVertexArrays(1, &mVao);
	}
	if (mPosVbo != 0) {
		glDeleteBuffers(1, &mPosVbo);
	}
	if (mUvVbo != 0) {
		glDeleteBuffers(1, &mUvVbo);
	}
	if (mEbo != 0) {
		glDeleteBuffers(1, &mEbo);
	}
}

Geometry* Geometry::createBox( float size ){
	Geometry* geometry = new Geometry();
	float halfSize = size / 2.0f;
	geometry->mIndicesCount = 36;

	float positions[] = {
		// 后面 (Back Face)
		-halfSize, -halfSize, -halfSize,  halfSize, -halfSize, -halfSize,  halfSize,  halfSize, -halfSize, -halfSize,  halfSize, -halfSize,
		// 前面 (Front Face)
		-halfSize, -halfSize,  halfSize,  halfSize, -halfSize,  halfSize,  halfSize,  halfSize,  halfSize, -halfSize,  halfSize,  halfSize,
		// 左面 (Left Face)
		-halfSize,  halfSize,  halfSize, -halfSize,  halfSize, -halfSize, -halfSize, -halfSize, -halfSize, -halfSize, -halfSize,  halfSize,
		// 右面 (Right Face)
		 halfSize,  halfSize,  halfSize,  halfSize,  halfSize, -halfSize,  halfSize, -halfSize, -halfSize,  halfSize, -halfSize,  halfSize,
		 // 下面 (Bottom Face)
		 -halfSize, -halfSize, -halfSize,  halfSize, -halfSize, -halfSize,  halfSize, -halfSize,  halfSize, -halfSize, -halfSize,  halfSize,
		 // 上面 (Top Face)
		 -halfSize,  halfSize, -halfSize,  halfSize,  halfSize, -halfSize,  halfSize,  halfSize,  halfSize, -halfSize,  halfSize,  halfSize
	};

	float uvs[] = {
			0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, // 后
			0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, // 前
			1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, // 左
			1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, // 右
			0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, // 下
			0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f  // 上
	};

	unsigned int indices[] = {
		0,  1,  2,  2,  3,  0,  // 后
		4,  5,  6,  6,  7,  4,  // 前
		8,  9,  10, 10, 11, 8,  // 左
		12, 13, 14, 14, 15, 12, // 右
		16, 17, 18, 18, 19, 16, // 下
		20, 21, 22, 22, 23, 20  // 上
	};

	GLuint& posVbo = geometry->mPosVbo, uvVbo = geometry->mUvVbo;

	glGenBuffers(1, &posVbo);
	glBindBuffer(GL_ARRAY_BUFFER, posVbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

	glGenBuffers(1, &uvVbo);
	glBindBuffer(GL_ARRAY_BUFFER, uvVbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(uvs), uvs, GL_STATIC_DRAW);

	glGenBuffers(1, &geometry->mEbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, geometry->mEbo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glGenVertexArrays(1, &geometry->mVao);
	glBindVertexArray(geometry->mVao);

	//VAO  0   posVbo
	glBindBuffer(GL_ARRAY_BUFFER, posVbo);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)0);

	//VAO 1  uvVBO        vertex buffer
	glBindBuffer(GL_ARRAY_BUFFER, uvVbo);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, geometry->mEbo);
	glBindVertexArray(0);
	return geometry;
}

Geometry* Geometry::createSphere( float size ){
	Geometry* geometry = new Geometry();
	return geometry;
}