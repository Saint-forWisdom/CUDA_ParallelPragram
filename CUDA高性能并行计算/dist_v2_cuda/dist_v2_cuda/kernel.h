#ifndef KERNEL_H
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include<stdio.h>
#define KERNEL_H
//kernel wrapper for computing array of distance values
void distanceArray(float* out, float* in, float ref, float len);

#endif // !KERNEL_H
