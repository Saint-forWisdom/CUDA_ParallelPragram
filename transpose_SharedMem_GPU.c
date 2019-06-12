__global__ void tranposeNaive(float *odata, float *idata, int width, int height)
{
	__shared__ float tile[TILE_WIDTH][TILE_WIDTH];


	int xIndex = blockIdx.x * TILE_DIM + threadIdx.x;
	int yIndex = blockIdx.x * TILE_DIM + threadIdx.y;

	int index_in = xIndex + width * yIndex;
	// 将tile中的列向坐标 转换为行向坐标

	xIndex = blockIdx.y * TILE_DIM + threadIdx.x;	// x方向的坐标
	yIndex = blockIdx.x * TILE_DIM + threadIdx.y;	// y方向的坐标
	int index_out = xIndex + height * yIndex;	// 在Mat中的坐标

	tile[threadIdx.y][threadIdx.x] = idata[index_in];//将数据写入shared Memory中
	__syncthreads();

	odata[Index_out] = tile[threadIdx.y][threadIdx.x];
}
// 读操作支持合并， 写操作不支持合并
// 以行为主元， 以宽度为步长
//
// 使用shared memory 使得读写都可以进行合并读写
// 把数据读入shared memory, 需要使用到__syncthreads();

