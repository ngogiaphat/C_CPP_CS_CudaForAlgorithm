using System;
using System.Collections.Generic;
class GFG {
    static int minDis(string s1, string s2, int n, int m, List<List<int>> dp){
        // If any string is empty, return the remaining characters of other string
        if(n == 0)
        return m;
        if(m == 0)
        return n;
        // To check if the recursive tree for given n & m has already been executed
        if(dp[n][m] != -1)
        return dp[n][m];
        // If characters are equal, execute
        // recursive function for n-1, m-1
        if(s1[n - 1] == s2[m - 1]){
            if(dp[n - 1][m - 1] == -1){
                return dp[n][m] = minDis(s1, s2, n - 1, m - 1, dp);
            }
            else
                return dp[n][m] = dp[n - 1][m - 1];
        };
        // If characters are nt equal, we need to find the minimum cost out of all 3 operations.
        else {
            int m1, m2, m3;	 // temp variables
            if(dp[n - 1][m] != -1){
                m1 = dp[n - 1][m];
            }
            else {
                m1 = minDis(s1, s2, n - 1, m, dp);
            }
            if(dp[n][m - 1] != -1){
                m2 = dp[n][m - 1];
            }
            else {
                m2 = minDis(s1, s2, n, m - 1, dp);
            }
            if(dp[n - 1][m - 1] != -1){
                m3 = dp[n - 1][m - 1];
            }
            else {
                m3 = minDis(s1, s2, n - 1, m - 1, dp);
            };
            return dp[n][m] = 1+ Math.Min(m1, Math.Min(m2, m3));
        };
    };
    // Driver code
    static void Main(){
        string str1 = "reth";
        string str2 = "enterprise";
        int n = str1.Length, m = str2.Length;
        List<List<int>> dp = new List<List<int>>();
        for(int i = 0; i < n + 1; i++){
        dp.Add(new List<int>());
            for(int j = 0; j < m + 1; j++){
                dp[i].Add(-1);
            };
        };
        Console.WriteLine(minDis(str1, str2, n, m, dp));
    };
};
// This code is contributed by divyeshrabadiya07.