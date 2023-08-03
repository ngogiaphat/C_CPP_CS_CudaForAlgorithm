#include<bits/stdc++.h>
using namespace std;
int main(){
    unordered_map<int, string> hashtable;
    hashtable[1] = "One";
    hashtable[2] = "Two";
    hashtable[3] = "Three";
    int keyToSearch = 2;
    auto it = hashtable.find(keyToSearch);
    if(it != hashtable.end()){
        cout << "Element found with key: " << it -> second << " and value: " << it->second;
    }
    else {
        cout << "Element not found";
    };
    return 0;
};