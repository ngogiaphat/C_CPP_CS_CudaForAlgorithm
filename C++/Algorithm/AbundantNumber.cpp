#include<bitset>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<numeric>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// function to calculate sum of divisors
int getSum(int n){
	int sum = 0;
	// note that this loop runs till square root of n
	for(int i=1; i<=sqrt(n); i++){
		if(n%i==0){
			// if divisors are equal,take only one of them
			if(n/i == i)
				sum = sum + i;
            // otherwise take both
			else {
				sum = sum + i;
				sum = sum + (n / i);
			};
		};
	};
	// calculate sum of all proper divisors only
	sum = sum - n;
	return sum;
};
// function to check Abundant Number
bool checkAbundant(int n){
	// return true if sum of divisors is greater than n
	return(getSum(n) > n);
};
// driver program to test above function
int main(){
	checkAbundant(12)? cout << "YES\n" : cout << "NO\n";
	checkAbundant(15)? cout << "YES\n" : cout << "NO\n";
	return 0;
};