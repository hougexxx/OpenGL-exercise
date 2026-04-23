#需求的最低cmake程序版本
cmake_minimum_required(VERSION 3.12)

#本工程的名称
project(OpenGL)

#本工程支持的C++版本
set(CMAKE_CXX_STANDARD 17)

#add_definitions(-DDEBUG)


file(GLOB ASSETS "./assets")
file(COPY ${ASSETS} DESTINATION ${CMAKE_BINARY_DIR})

#添加第三方头文件目录
include_directories(SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/thirdParty/include)

#link  directories
link_directories(SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/thirdParty/lib)

add_subdirectory(Wrapper)
add_subdirectory(Application)
add_subdirectory(glframework)

#本工程主程序文件及输出程序名称
add_executable(opengl_Study "main.cpp" "glad.c")

#把glfw   link到exe中
target_link_libraries(opengl_Study glfw3.lib wrapper app fw)