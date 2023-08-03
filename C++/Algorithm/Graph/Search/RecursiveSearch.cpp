#include<bits/stdc++.h>
using namespace std;
int recursiveSearch(int arr[], int l, int r, int t){
    if(l > r)
        return -1;
    int m = (l + r)/2;
    if(arr[m] == t)
        return m;
    if(arr[m] > t){
        return recursiveSearch(arr, l, m - 1, t);
    }
    else {
        return recursiveSearch(arr, m + 1, r, t);
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
    int t;
    cout << "\n Enter the value to look for: ";
    cin >> t;
    int index = recursiveSearch(arr, 0, n - 1, t);
    if(index == -1){
        cout << "\n Element not found";
    }
    else {
        cout << "\n Element found at index: " << index;
    };
    return 0;
};