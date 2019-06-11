// using shared memory 
// 我不明白shared memory的访问权限， 都是那些程序可以访问shared memory
// 是一个sm上的， 还是从软件角度看的一个block的。
__global__ void MatrxiMulKernel(float* Md, float* Nd, float* Pd, int Width)
{
	__shared__ float Mds[TILE_WIDTH][TILE_WIDTH];
	__shared__ float Nds[TILE_WIDTH][TILE_WIDTH];

	int bx = blockIdx.x; int by = blockIdx.y;
	int tx = threadIdx.x; int ty = threadIdx.y;

	int Row = bx * TILE_WIDTH + tx; // TILE_WIDTH == blockDim.x ???
	int Col = by * TILE_WIDTH + ty;

	float Pvalue = 0;

	for(int m = 0; m < Width / TILE_WIDTH; m++)
	{
		//由global memory 写入共享内存
		Mds[ty][tx] = Md[ROW*Width + (m * TILE_WIDTH + tx)];
		Nds[ty][tx] = Nd[Col + (m*TILE_WIDTH + ty) * Width];
		__syncthreads(); // 数据读入shared memory 同步

		for(int k = 0; k < TILE_WIDTH; k++)
			Pvalue += Mds[ty][k] * Nds[k][tx];
		__syncthreads(); // 计算数据，准备输出同步
	} 
	Pd[Row*Width + col] = Pvalue;
	// 从sharedMemory写入globalMemory
}

