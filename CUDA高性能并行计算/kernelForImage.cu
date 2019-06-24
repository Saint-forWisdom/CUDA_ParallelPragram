__global__
void kernel2D(uchar4 *d_output, int w, int h, ...)
{
	// uchar4的四个成员看作是图像的四个通道 
	// Compute column and row indices
	const int c = blockIdx.x*blockDim.x + threadIdx.x;
	const int r = blockIdx.y*blockDim.y + threadIdx.y;
	const int i = r * w + c;

	// check if within image bounds.
	if((c>=w) || (r >= h))
		return error;

	d_output[i].x = RED_FORMULA;		// compute red
	d_output[i].y = GREEN_FORNULA;		// compute green
	d_output[i].z = BLUE_FORMULA;		// compute blue
	d_output[i].w = 255;			// Fully opaque
}

