float *Md
int size = Width * Width * sizeof(float);
...
cudaMalloc((void**)&Md, size);
...
cudaFree(Md);

// attention 
// (void **)&Md Pointer to device memory
// Md could not be operated in CPU memory.
// size is the molloc Space size.
