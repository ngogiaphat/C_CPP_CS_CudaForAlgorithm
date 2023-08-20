using System;
using System.Collections.Generic;
class RETH {
    // to calculate nCr DP approach
    static int binomialCoeff(int n, int k){
        int []C = new int[k + 1];
        // nC0 is 1
        C[0] = 1;
        for(int i = 1; i <= n; i++){
            // compute next row of pascal triangle using the previous row
            for(int j = Math.Min(i, k); j > 0; j--)
            C[j] = C[j] + C[j - 1];
        };
        return C[k];
    };
    // returns count of Geometric Progression subsequences with length 3 and common ratio r
    static long subsequences(int []a, int n, int r){0
        // hashing to maintain left and right array elements to the main count
        Dictionary<int, int> left = new Dictionary<int, int>();
        Dictionary<int, int> right = new Dictionary<int, int>();
        // stores the answer
        long ans = 0;
        // traverse through the elements
        for(int i = 0; i < n; i++){
            if(right.ContainsKey(a[i])){
                right[a[i]]++;
            }
            else {
                right.Add(a[i], 1);
            };
        };
        // if ratio to 1
        if(r == 1){
            // traverse the count in hash
            foreach(KeyValuePair<int, int> i in right){
                // calculating nC3, where 'n' is the number of times each number is repeated in the input
                ans += binomialCoeff(i.Value, 3);
            }
            return ans;
        };
        // traverse through all elements and find out the number of elements as k1*k2
        for(int i = 0; i < n; i++){
            // keep the count of left and right elements left is a[i]/r and right a[i]*r
            long c1 = 0, c2 = 0;
            // if the current element is divisible by k, count elements in left hash
            if(a[i] % r == 0)
            if(left.ContainsKey(a[i] / r))
                c1 = left[a[i] / r];
            // decrease the count in right hash
            if(right.ContainsKey(a[i])){
                right[a[i]]--;
            }
            else {
                right.Add(a[i], -1);
            };
            // number of right elements
            if(right.ContainsKey(a[i] * r))
            c2 = right[a[i] * r];
            // calculate the answer
            ans += c1 * c2;
            if(left.ContainsKey(a[i])){
                left[a[i]]++;
            }
            // left count of a[i]
            else {
                left.Add(a[i], 1);
            };
        };
        return ans;
    };
    // driver code
    public static void Main(String[] args){
        int []a = {1, 2, 6, 2, 3, 6, 9, 18, 3, 9};
        int n = a.GetLength(0);
        int r = 3;
        Console.Write(subsequences(a, n, r));
    };
};