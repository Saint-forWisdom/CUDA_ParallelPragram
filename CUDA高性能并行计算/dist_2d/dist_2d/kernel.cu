
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include<GL/glew.h>

#define W 500
#define H 500
#define TX 32		// number of threads per block along x-axis
#define TY 32

#include<stdlib.h>
#include <stdio.h>

__device__
unsigned char clip(int n) { return n > 255 ? 255 : (n < 0 ? 0 : n); }

__global__
void distanceKernel(uchar4 *d_output, int w, int h, int2 pos)
{
	// uchar4的四个成员看作是图像的四个通道 
	// Compute column and row indices
	const int c = blockIdx.x*blockDim.x + threadIdx.x;
	const int r = blockIdx.y*blockDim.y + threadIdx.y;
	const int i = r * w + c;

	// check if within image bounds.
	if ((c >= w) || (r >= h))
		return ;
	// Compute the distance (in pixel spacings)
	const int d = sqrtf((c - pos.x) * (c - pos.x) + (r - pos.y)*(r - pos.y));

	// convert distance to intensity value on interval [0, 255]
	const unsigned char intensity = clip(255 - d);		// 越远越 intensity 越小

	d_output[i].x = intensity;		// compute red
	d_output[i].y = intensity;		// compute green
	d_output[i].z = 0;		// compute blue
	d_output[i].w = 255;			// Fully opaque
}

int main(void)
{
	uchar4 *out = (uchar4*)calloc(W*H, sizeof(uchar4));		// host memory distributed
	uchar4 *d_out;					// pointer to device memory
	cudaMalloc(&d_out, W*H * sizeof(uchar4));  // device memory distributed

	const int2 pos = { 0, 0 };// 设置参考点位置
	const dim3 blockSize(TX, TY); 
	const int bx = (W + TX - 1) / TX;
	const int by = (H + TY - 1) / TY;
	const dim3 gridSize(bx, by);

	distanceKernel << <gridSize, blockSize >> > (d_out, W, H, pos);

	cudaMemcpy(out, d_out, W*H * sizeof(uchar4), cudaMemcpyDeviceToHost);

	cudaFree(d_out);
	free(out);

	return 0;
}
// 使用Nsight查看内存