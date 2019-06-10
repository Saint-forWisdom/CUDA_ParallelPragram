// CUDA 算法框架，三步走
// 第一步：分配内存
//--allocate anda initialize the matrices M, N, P
//--I/O to read the input matrices M and N
// 第二步：将输入传入到设备中，进行计算
// --M*N on the device
// --MatrixMulOnDevice(M, N, P, width)
// 第三步：将计算结果返回到CPU中，释放设备中的内存
// --I/O to write the output matrix P
// --Free matrices M, N, P
void MatrixMulOnDevice(float* M, float* N, float* P, int width)
{
	int size = width * width * sizeof(float);
	// 1, load M and N to device memory
	cudaMalloc(Md, size);
	cudaMemcpy(Md, M, size, cudaMemcpyHostToDevice);
	cudaMalloc(Nd, size);
	cudaMemcpy(Nd, N, size, cudaMemcpyHostTODevice);
	
	//Allocate P on the device
	cudaMalloc(Pd, size);
	
	// 2, Kernel invocation code
	dim3 dimBlock(Width, Width);
	dim3 dimGrid(1, 1);

	Matrixkernel<<<dimGrid, dimBlock>>>(Md, Nd, Pd);
	// 3, Read P from device
	cudaMemcpy(P, Pd, size, cudaMemcpyDeviceToHost);
	MemFree(Md);
	MemFree(Nd);
	MemFree(Pd);
}

// matrix multipication kernel - thread specification
__global__ void MatrixKernel(float * Md, float * Nd, float Pd, int Width)
{
	// 2D Thread ID
	int tx = threadIdx.x;
	int ty = threadIdx.y;

	// Pvalue stores the Pd element that is computed by the thread
	float Pvalue = 0;
	for(int k = 0; k < Width; k++){
		float MdElement = Md[ty*Md.width + k];
		float NdElement = Nd[k*Nd.width + tx];
		Pvalue += MdElement * NdElement;
	}
	//Write the matrix to device memory each thread writes one element
	Pd[ty*Width + tx] = Pvalue;
}






