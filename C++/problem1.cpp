#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int* A = new int[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    int newSize = n;
    for(int i = 0; i < n; i++){
        if(A[i] % 2 == 0){
            newSize++;
        }
    }
    int* newArray = new int[newSize];
    int index = 0;
    for (int i = 0; i < n; i++){
        if(A[i] % 2 == 0){
            newArray[index] = 0;
            index++;
        }
        newArray[index] = A[i];
        index++;
    }
    cout << newSize << endl;
    for(int i = 0; i < newSize; i++){
        cout << newArray[i] << " ";
    }
    delete[] A;
    delete[] newArray;
    return 0;
}