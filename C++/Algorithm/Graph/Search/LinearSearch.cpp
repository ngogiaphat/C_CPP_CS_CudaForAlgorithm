#include<bits/stdc++.h>
using namespace std;
int linearSearch(int arr[], int n, int key){
    for(int i =0; i < n; i++){
        if(arr[i] == key){
            return i;
        };
    };
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
    int index = linearSearch(arr, n, key);
    if(index == -1){
        cout << "\n Element not found";
    }
    else {
        cout << "\n Element found at index: " << index;
    }
    return 0;
};