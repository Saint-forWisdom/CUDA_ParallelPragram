#include "aux_functions.h"
/*
#define N 64

int main(void) 
{
	float in[N] = { 0.0f };
	float out[N] = { 1.1f };

	const float ref = 0.5f;
	for (int i = 0; i < N; i++) {
		in[i] = scale(i, N);
	}

	distanceArray(out, in, ref, N);

	return 0;
}
*/

#include<stdlib.h>
#define N 2000000

int main(void)
{
	float* in_m = (float *)calloc(N, sizeof(float));
	float* out_m = (float *)calloc(N, sizeof(float));

	const float ref = 0.5f;
	for (int i = 0; i < N; i++) {
		in_m[i] = scale(i, N);
	}

	distanceArray(out_m, in_m, ref, N);

	free(in_m);
	free(out_m);
	return 0;
}