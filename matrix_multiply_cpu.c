// using cpu to inplement Matrix Multiply
void MatrixMulOnHost(float* M, float * N, float * p, int width)
{
	for(int i = 0; i < width; i++){
		for(int j = 0; j < width; j++){
			float sum = 0;
			for(int k = 0; k < width; k++){
				float a = M[i*width + k]; // 横向
				float b = N[k*width + j]; // 纵向
				sum += a * b;
			} // for k from 0 to width-1
			p[i * width + j] = sum;
		}// for j from 0 to width-1
	}// for i from 0 to width-1

