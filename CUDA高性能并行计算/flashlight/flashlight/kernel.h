// 作为kernel的头文件之外， 也作为main的头文件
#include "device_launch_parameters.h"

#include <stdio.h>
#include<stdlib.h>
#ifdef _WIN32
#define WINDOWS_LEAN_AND_MEAN
#define NOMINMAX
#include <Windows.h>
#endif // _WIN32

#ifdef  __APPPLE__
#include<GL/glut.h>
#else
#include<GL/glew.h>
#include<GL/freeglut.h>
#endif //  __APPPLE__

#include "cuda_runtime.h"
#include"cuda_gl_interop.h"



#ifndef KERNEL_H
#define KERNEL_H

struct uchar4;
struct int2;

void kernelLauncher(uchar4 *d_out, int w, int h, int2 pos);
// 封装cuda的kernel函数

#endif // !KERNEL_H

