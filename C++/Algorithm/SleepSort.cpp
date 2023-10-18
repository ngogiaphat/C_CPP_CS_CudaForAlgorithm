#include<thread>
#include<chrono>
#include<iostream>
using namespace std;
void sleepSort(int x){
    this_thread::sleep_for(chrono::seconds(x));
    cout<< x <<" ";
}
int main(){
    int arr[] = {3, 1, 4, 2, 6, 5, 5, 12, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    thread threads[n];
    for(int i = 0; i < n; i++){
        threads[i] = thread(sleepSort, arr[i]);
    }
    for(int i = 0; i < n; i++){
        threads[i].join();
    }
    return 0;
}