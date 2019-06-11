// 去除block的长度限制
// one block -> many block 
// TILE_WIDTH -> BLOCKSIZE
//
/* 编写kernel */
__global__ void MatrixMulkernel(float *Md, float* Nd, float* Pd, int Width)
{
	int Row = blockIdx.y * blockDim.y + threadIdx.y;
	int Col = blockIdx.x * blockDim.x + threadIdx.x;

	float Pvalue = 0;
	for(int k = 0; k < Width; k++)
		Pvalue += Md[Row * width + k] * Nd[k * Width + Col];

	Pd[Row, Col] = Pvalue;
}

// kernel调用

dim3 dimGrid(Width / TILE_WIDTH, Height / TILE_WIDTH); // dimGrid 定义需要多少个block
dim3 dimBlock(TILE_WIDTH, TILE_WIDTH);			// dimBlock定义一个block中有多少个thread
MatrixMulKernel<<<dimGrid, dimBlock>>>(Md, Nd, Pd, TILE_WIDTH);		// 一个block的宽度？？？？

