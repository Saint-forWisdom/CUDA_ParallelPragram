__global__ void tranposeNaive(float *odata, float *idata, int width, int height)
{
	int xIndex = blockIdx.x * TILE_DIM + threadIdx.x;
	int yIndex = blockIdx.x * TILE_DIM + threadIdx.y;

	int index_in = xIndex + width * yIndex;
	int index_out = yIndex + width * xIndex;	// 在Mat中的坐标

	odata[Index_out] = idata[index_in];
}
// 读操作支持合并， 写操作不支持合并
// 以行为主元， 以宽度为步长
