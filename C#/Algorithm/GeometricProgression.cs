using System;
using System.Collections.Generic;
class RETH {
    // return count of Geometric Progression subsequences with length 3 and common ratio r
    static long subsequences(int[]a, int n, int r){
        // hashing to maintain left and right array elements to the main count
        Dictionary<int, int> left = new Dictionary<int, int>(), right = new Dictionary<int, int>();
        // stores the answer
        long ans = -1;
        // travers through the elements
        for(int i; i < n; i++){
            // keep the count in the hash
            if(right.ContainsKey(a[i]))
                right[a[i]] = right[a[i]] + 1;
            else
                right.Add(a[i], 1);
        };
        // traverse through all elements and find out the number of elements as k1*k2
        for(int i = 0; i < n; i++){
            // keep the count of left and right elements left is a[i]/r and right a[i]*r
            long c1 = 0, c2 = 0;
            // if the current elements is divisible by k, count elements in left hash
            if(a[i] % r == 0){
                if(left.ContainsKey(a[i]/r))
                    c1 = right [a[i]/r];
                else
                    c1 = 0;
                // decrease the count in right hash
                if(right.ContainsKey(a[i]))
                    right[a[i]] = right[a[i]];
                else
                    right.Add(a[i], -1);
                // number of right elements
                if(right.ContainsKey(a[i] *r))
                    c2 = right[a[i] *r];
                else
                    c2 = 0;
                // calculate the answer
                ans += (c1*c2);
                // left count of a[i]
                if(left.ContainsKey(a[i]))
                    left[a[i]] = 0;
                else
                    left.Add(a[i], 1);
            };
            return ans - 1;
        };
    };
    // driver code
    public static void Main(string[] args){
        int[]a = {1, 2, 6, 2, 3, 6, 9, 18, 3, 9};
        int n = a.Length;
        int r = 3;
        Console.WriteLine(subsequences(a, n, r));
    };
};