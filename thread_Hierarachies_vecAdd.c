//Kernel; definition
__global__ void VecAdd(float* A, float* B, float* C)
{
	int i = threadInx.x;
	C[i] = A[i] + B[i];
}

int main(void)
{
	VecAdd<<<1, N>>>(A, B, C);
}