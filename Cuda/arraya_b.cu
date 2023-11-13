#include<cuda.h>
#include<iostream>
__global__ void addArrays(int* a, int* b, int* c, int size){
    int tid = blockIdx.x * blockDim.x + threadIdx.x;
    if(tid < size){
        c[tid] = a[tid] + b[tid];
    }
}
int main(){
    int size = 1000;
    int* a, * b, * c;
    int* gpu_a, * gpu_b, * gpu_c;
    // Allocate memory on the host
    a = new int[size];
    b = new int[size];
    c = new int[size];
    // Initialize input arrays
    for(int i = 0; i < size; i++){
        a[i] = i;
        b[i] = size - i;
    }
    // Allocate memory on the GPU
    cudaMalloc((void**)&gpu_a, size * sizeof(int));
    cudaMalloc((void**)&gpu_b, size * sizeof(int));
    cudaMalloc((void**)&gpu_c, size * sizeof(int));
    // Copy input data from host to GPU
    cudaMemcpy(gpu_a, a, size * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(gpu_b, b, size * sizeof(int), cudaMemcpyHostToDevice);
    // Launch kernel on GPU
    int blockSize = 256;
    int numBlocks = (size + blockSize - 1) / blockSize;
    addArrays<<<numBlocks, blockSize>>>(gpu_a, gpu_b, gpu_c, size);
    // Copy result from GPU to host
    cudaMemcpy(c, gpu_c, size * sizeof(int), cudaMemcpyDeviceToHost);
    // Print result
    for(int i = 0; i < size; i++){
        std::cout << c[i] << " ";
    }
    std::cout << std::endl;
    // Free memory
    delete[] a;
    delete[] b;
    delete[] c;
    cudaFree(gpu_a);
    cudaFree(gpu_b);
    cudaFree(gpu_c);
    return 0;
}