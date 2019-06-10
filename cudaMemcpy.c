// Host to host
// host to device
// device to device
// device to host
// cuda的数据传输
cudaMemcpy(Md, M, size, cudaMemcpyHostToDevice);
//notice: 
//Md: destination.para, device memory pointer, 
//M: source.para, host memory pointer
//size: data szie
//cudaMemcpyHostToDevice: 从主机端将数据copy到设备端
cudaMemcpy(P, pd, size, cudaMemcpyDeviceToHost);
//notice;
//look up please.
