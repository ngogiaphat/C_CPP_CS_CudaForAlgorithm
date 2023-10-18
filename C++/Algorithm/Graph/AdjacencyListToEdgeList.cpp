#include<string>
#include<vector>
#include<sstream>
#include<stdio.h>
#include<iostream>
#include<windows.h>
#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int>> edge;
int a[10001][10001];
int main(){
    cin >> n;
    cin.ignore();
    for(int i = 1; i <= n; i++){
        string s, num;
        getline(cin, s);
        stringstream ss(s);
        while(ss >> num){
            if(stoi(num) > i){
                edge.push_back({i, stoi(num)});
            };
        };
    };
    for(auto it: edge){
        cout << it.first << " " << it.second << endl;
    };
};