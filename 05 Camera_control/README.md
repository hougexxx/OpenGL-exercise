OpenGL-exercise

- exercise about OpenGL         
- 基于C++，OpenGL 4.6以及cmake制作的。
- 主要内容是进行camera的练习。



目的：camera control 练习  
对原来空间中的两张图片加入了相机控制，可以通过鼠标左键点击移动，鼠标中键滚轮移动，鼠标中键点击移动等事件，
控制相机的位置。<br>通过相对运动的原理进而给人以控制空间中物体的感觉。也就是“轨迹球相机”。

图示：<br>
<img src="https://github.com/hougexxx/OpenGL-exercises/blob/e8857da500a44394ec54a1bbbc3919296d013d9c/05%20Camera_control/README_picture/CameraControl_1.png" width=40%>
<img src="https://github.com/hougexxx/OpenGL-exercises/blob/e8857da500a44394ec54a1bbbc3919296d013d9c/05%20Camera_control/README_picture/CameraControl_2.png" width=40%>

增加内容如下：

- 增加CameraControl父类
- 增加了CameraControl的TrackBallCameraControl子类



其他内容如下保持不变：

main.cpp为主函数。

glad.c函数用于导入和OpenGL相关的函数。

Application是应用层的函数库，里面封装了init，update，destroy函数。

Wrapper中封装了OpenGL的错误检查函数。

assets中是项目所需要的资源文件。包括glsl文件，以及用于制作纹理的图片。

glframework是整个项目的框架，封装了关于shader着色器和texture纹理相关的函数。

thirdparty中是需要的第三方库。

