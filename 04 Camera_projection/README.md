OpenGL-exercise

- exercise about OpenGL         
- 基于C++，OpenGL 4.6以及cmake制作的。
- 主要内容是进行camera的练习。



目的：perspective projection练习   采用透视投影从上方向下观察前后位置不一样的两张图像

图示：![](\README_picture\cameraMove.png)



增加内容如下：

- 增加perspectiveMatrix矩阵，用于做投影变换
- 增加了另外一张图像的VBO数据，修改了对应的纹理uv，修改了绘制定点数（绘制顺序的不同会造成遮挡不同，后续需要采用Z-buffer做判定）



其他内容如下保持不变：

main.cpp为主函数。

glad.c函数用于导入和OpenGL相关的函数。

Application是应用层的函数库，里面封装了init，update，destroy函数。

Wrapper中封装了OpenGL的错误检查函数。

assets中是项目所需要的资源文件。包括glsl文件，以及用于制作纹理的图片。

glframework是整个项目的框架，封装了关于shader着色器和texture纹理相关的函数。

thirdparty中是需要的第三方库。



