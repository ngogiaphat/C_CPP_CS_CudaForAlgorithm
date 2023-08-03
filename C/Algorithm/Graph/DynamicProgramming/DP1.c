#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Utility function to find the minimum of three numbers
int min(int x, int y, int z){
	if(x <= y && x <= z)
		return x;
	if(y <= x && y <= z)
		return y;
	return z;
};
int editDistDP(char* str1, char* str2, int m, int n){
	// Create a table to store results of subproblems
	int dp[m + 1][n + 1];
	// Fill d[][] in bottom up manner
	for(int i = 0; i <= m; i++){
		for(int j = 0; j <= n; j++){
			// If first string is empty, only option is to insert all characters of second string
			if(i == 0)
				dp[i][j] = j; // Min. operations = j
			// If second string is empty, only option is to remove all characters of second string
			else if(j == 0)
				dp[i][j] = i; // Min. operations = i
			// If last characters are same, ignore last char and recur for remaining string
			else if(str1[i - 1] == str2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			// If the last character is different, consider all possibilities and find the minimum
			else
				dp[i][j] = 1 + min(
                    dp[i][j - 1], // insert
                    dp[i - 1][j], // remove
                    dp[i - 1][j - 1] // replace
                );
		};
	};
	return dp[m][n];
};
// Driver code
int main(){
	char str1[] = "sunday";
	char str2[] = "saturday";
	int m = strlen(str1);
	int n = strlen(str2);
	printf("%d\n", editDistDP(str1, str2, m, n));
	return 0;
};