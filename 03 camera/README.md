OpenGL-exercise

- exercise about OpenGL         
- 基于C++，OpenGL 4.6以及cmake制作的。
- 主要内容是进行camera的练习。



目的：在让camera   在Z轴为0.5时候左右动态观察图片

图示：![camera](https://github.com/hougexxx/OpenGL-exercises/blob/1f413adc52e84329ba67867eee905860d985ade3/03%20camera/README_picture/cameraMove.png)


增加内容如下：

- 增加了一些transform矩阵    用于控制物体平移，旋转，缩放，以及它们的复合矩阵
- 增加了viewMatrix矩阵  用于控制相机的移动

- 增加了float ValueToTime函数用于随时间控制相机X轴的移动



其他内容如下保持不变：

main.cpp为主函数。

glad.c函数用于导入和OpenGL相关的函数。

Application是应用层的函数库，里面封装了init，update，destroy函数。

Wrapper中封装了OpenGL的错误检查函数。

assets中是项目所需要的资源文件。包括glsl文件，以及用于制作纹理的图片。

glframework是整个项目的框架，封装了关于shader着色器和texture纹理相关的函数。

thirdparty中是需要的第三方库。



