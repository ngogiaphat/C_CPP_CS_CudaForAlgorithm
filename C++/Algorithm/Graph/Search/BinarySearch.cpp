#include<bits/stdc++.h>
using namespace std;
int binSearch(int arr[], int l, int r, int x){
    while(l <= r){
        int m = l + (r - l) / 2;
        if(arr[m] == x)
            return m;
        if(arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    };
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
    int target;
    cout << "\n Enter the value to look for: ";
    cin >> target;
    int index = binSearch(arr, 0, n - 1, target);
    if(index == -1){
        cout << "\n Element not found";
    }
    else {
        cout << "\n Element found at index: " << index;
    }
    return 0;
};