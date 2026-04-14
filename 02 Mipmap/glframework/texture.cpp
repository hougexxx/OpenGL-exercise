#include "texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "../Application/stb_image.h"

Texture::Texture(const std::string& path, unsigned int unit) {
	mUnit = unit;
	//1 stbImage 读取图片
	int channels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load(path.c_str(), &mWidth, &mHeight, &channels, STBI_rgb_alpha);

	//2 生成纹理对象并激活单元绑定
	glGenTextures(1, &mTexture);
	glActiveTexture(GL_TEXTURE0+mUnit);
	glBindTexture(GL_TEXTURE_2D, mTexture);


	//****************************************************************************************
	////制作每一级别的mipmap     ？？？"可以尝试做一下每一个级别的mipmap"   对原始图片信息   滤波->采样  
	// 	int width = mWidth;
	//  int height = mHeight;
	//for (int level = 0; true; level++) {
	//	glTexImage2D(GL_TEXTURE_2D, level, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

	//	if (width == 1 && height == 1) {
	//		break;
	//	}

	//	width = width > 1 ? width / 2 : 1;
	//	height = height > 1 ? height / 2 : 1;
	//}
	//****************************************************************************************
	

	//*********************************

	//3 传输纹理数据 ******正式开辟显存，之前的都是在显存上声明一块数据，用来放置纹理
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mWidth, mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	//*********************************
	
	//释放数据
	stbi_image_free(data);

	//设置过滤方式
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);

	//设置包裹
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);//U
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);//V
}

Texture::~Texture() {
	if (mTexture != 0) {
		glDeleteTextures(1, &mTexture);
	}
}


void Texture::bind() {
	glActiveTexture(GL_TEXTURE0 + mUnit);
	glBindTexture(GL_TEXTURE_2D, mTexture);
} 