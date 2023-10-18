#include<bits/stdc++.h>
#define N 3
using namespace std;
// function for matrix multiplication
void multiply(int mat[][N], int res[][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            res[i][j] = 0;
            for(int k = 0; k < N; k++){
                res[i][j] += mat[i][k] * mat[k][j];
            };
        };
    };
};
// function to check idempotent property of matrix
bool checkIdempotent(int mat[][N]){
    //calculate multiplication of matrix with itself and store it into res
    int res[N][N];
    multiply(mat, res);
    // check if res == mat
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(mat[i][j] != res[i][j]){
                return false;
            };
        };
    };
    return true;
};
// driver function
int main(){
    int mat[N][N] = {
        {2, -2, -4},
        {-1, 3, 4},
        {1, -2, -3}
    };
    // checkIdempotent function call
    if(checkIdempotent(mat)){
        cout << "Idempotent Matrix" << endl;
    }
    else {
        cout << "Not Idempotent Matrix" << endl;
    };
    return 0;
};