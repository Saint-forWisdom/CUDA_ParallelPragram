__global__
void kernel2D(float *d_out, int w, int h, ...)
{
	// Compute column and row indices
	const int c = blockIdx.x*blockDim.x + threadIdx.x;
	const int r = blockIdx.y*blockDim.y + threadIdx.y;
	const int i = r * w + c;

	// check if within image bounds.
	if((c>=w) || (r >= h))
		return error;

	d_out[i] = INSERT_CODE_HERE;  // compute/ store pixel in device array.
}

