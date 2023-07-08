#include <stdio.h>
#include <cuda_runtime.h>
__global__ void hashFunction(const char* input, int* output){
    int tid = blockIdx.x * blockDim.x + threadIdx.x;
    output[tid] = input[tid] % 256;
}
int main(){
    const int size = 256;
    const int threadsPerBlock = 256;
    const int numBlocks = size / threadsPerBlock;
    char input[size] = "Hello, CUDA!";
    int output[size];
    char* dev_input;
    int* dev_output;
    cudaMalloc((void**)&dev_input, size * sizeof(char));
    cudaMalloc((void**)&dev_output, size * sizeof(int));
    cudaMemcpy(dev_input, input, size * sizeof(char), cudaMemcpyHostToDevice);
    hashFunction<<<numBlocks, threadsPerBlock>>>(dev_input, dev_output);
    cudaMemcpy(output, dev_output, size * sizeof(int), cudaMemcpyDeviceToHost);
    cudaFree(dev_input);
    cudaFree(dev_output);
    for(int i = 0; i < size; i++){
        printf("%d ", output[i]);
    }
    printf("\n");
    return 0;
}