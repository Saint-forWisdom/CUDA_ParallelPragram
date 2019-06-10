//kernel definition
__global__ void MatAdd(float A[N][N], float B[N][N], float C[N][N])
{
	int i = threadIdx.x;
	int j = threadIdx.y;
	C[i][j] = A[i][j] + B[i][j];
}

int main(void)
{
	...
	// kernel invocate with one block of N*N*1 threads
	int numBlocks = 1;
	dim3 threadsPerBlock(N,N);
	MatAdd<<<numBlocks, threadsPerBlock>>>(A, B, C);
	// numblock 使用numblock个blocks
	// threadPerBlock 2D block
}


//version 2
__global__ void MatAdd(float A[N][N], float B[N][N], float C[N][N])
{
	int i = blockIdx.x * blockDim.x + threadIdx.x;
	int j = blockIdx.y * blockDim.y + threadIdx.y;
	if (i < N && j < N)
		C[i][j] = A[i][j] + B[i][j];
}

int main(void)
{
	...
	//kernel invovation 
	dim3 threadsPerBlock(16, 16);
	// 16*16 Threads Per Block

	dim3 numBlocks(N/threadsPerBlocks.x, N / threadsPerBlock.y);
	MatAdd<<<numBlocks, threadsPerBlock>>>(A, B, C);
	// numBlocks 2D ThreadBlock 
}

