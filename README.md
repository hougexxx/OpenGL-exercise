# OpenGL-exercise
exercise about OpenGL

所有OpenGL项目是基于C++ 17，OpenGL 4.6以及cmake 4.1.1制作的。

main.cpp为主函数。

glad.c函数用于导入和OpenGL相关的函数。

Application中是应用层的函数库，里面封装了init，update，destroy函数。

Wrapper中封装了OpenGL的错误检查函数。

assets中是项目所需要的资源文件。包括glsl文件，以及用于制作纹理的图片。

glframework是整个项目的框架，封装了关于shader着色器和texture纹理相关的函数。

thirdparty中是需要的第三方库。

