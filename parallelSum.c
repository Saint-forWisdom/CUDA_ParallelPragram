// using parallel reduction to add nums;
__shared__ float partialSum[];
// ... load into shared memory
unsigned int t = threadIdx.x;
for (unsigned int stride = threadIdx.x / 2; stride > 0; stride /= 2 )
{
	__syncthreads();
	if(t < 2) == 0)
		partialSum[t] += partialSum[t + stride];
}



