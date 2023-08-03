#include<bits/stdc++.h>
using namespace std;
int jumpSearch(int arr[], int x, int n){
    int step = sqrt(n);
    int prev = 0;
    while(arr[min(step, n) - 1] < x){
        prev = step;
        step += sqrt(n);
        if(prev >= n)
            return -1;
    };
    while(arr[prev] < x){
        prev++;
        if(prev == min(step, n))
            return -1;
    };
    if(arr[prev] == x)
        return prev;
    return -1;
};
int main(){
    int n;
    cout << "Enter the number of elements of the array: ";
    cin >> n;
    int arr[n];
    cout << "\n Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    };
    int key;
    cout << "\n Enter the value to look for: ";
    cin >> key;
    int index = jumpSearch(arr, key, n);
    if(index == -1){
        cout << "\n Element not found";
    }
    else {
        cout << "\n Element found at index: " << index;
    };
    return 0;
};