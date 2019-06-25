#include "kernel.h"
#define TX 32
#define TY 32

// 从这里开始。。。 
//openGL不一定被安装好了

__device__ 
unsigned char clip(int n) {return( n >= 255 ? 255 : (n < 0 ? 0 : n)); }

__global__ 
void distanceKernel(uchar4 *d_out, int w, int h, int2 pos) {
	const int c = blockIdx.x * blockDim.x + threadIdx.x;
	const int r = blockIdx.y * blockDim.y + threadIdx.y;
	if ((c >= w) || (r >= h)) return;
	const int i = r * w + c;
	// important formula
	const int dist = sqrtf((pos.x - c) * (pos.x - c) + (pos.y - r) * (pos.y - r));
	const unsigned char d = clip(255 - dist);
	d_out[i].x = d; // RED
	d_out[i].y = d; // GREEN
	d_out[i].z = 0; // blue
	d_out[i].w = 0;	// opaque
}

void kernelLauncher(uchar4 * d_out, int w, int h, int2 pos)
{
	dim3 blockSize(TX, TY);
	dim3 gridSize((w + TX - 1) / TX, (h + TY - 1) / TY);		// 分配多少个block
	distanceKernel << <gridSize, blockSize >> > (d_out, w, h, pos);
}
