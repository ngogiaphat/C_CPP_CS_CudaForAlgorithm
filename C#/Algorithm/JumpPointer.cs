using System;
using System.Collections.Generic;
public class GFG {
    public static int R = 0;
    public static int getLen(int n){
        int len = (int)(Math.Log(n) / Math.Log(2)) + 1;
        return len;
    };
    public static void set_jump_pointer(List<List<int>> jump, List<int> node, int len, int n){
        for(int j = 1; j <= len; j++){
            for(int i = 0; i < n; i++){
                jump[node[i]][j] = jump[jump[node[i]][j - 1]][j - 1];
            };
        };
    };
    public static void constructGraph(List<List<int>> jump, List<int> node, List<int> isNode, int c, int p, int i){
        node[i] = c;
        if(isNode == 0){
            isNode = 1;
            jump[0] = p;
        };
        return;
    };
    public static void jumpPointer(List<List<int>> jump, List<int> isNode, int x, int L, int n){
        int j = 0, curr = x, k = L;
        if(x > n || isNode[x] == 0) {
            Console.WriteLine("Node is not present in graph ");
            return;
        };
        while(L > 0){
            if((L & 1) == 1)
                x = jump[x][j];
            L = L >> 1;
            j++;
        };
        Console.WriteLine(k + "th parent of node " + curr + " is = " + x);
        return;
    };
    public static void Main(){
        int n = 11;
        int len = getLen(n);
        List<List<int>> jump = new List<List<int>>();
        for(int i = 0; i <= n; i++){
            jump.Add(new List<int>());
            for(int j = 0; j <= len; j++){
                jump[i].Add(0);
            };
        };
        List<int> node = new List<int>();
        for(int i = 0; i <= n; i++){
            node.Add(0);
        };
        List<int> isNode = new List<int>();
        for(int i = 0; i <= n; i++){
            isNode.Add(0);
        };
        R = 2;
        constructGraph(jump, node, isNode, 2, 0, 0);
        constructGraph(jump, node, isNode, 5, 2, 1);
        constructGraph(jump, node, isNode, 3, 5, 2);
        constructGraph(jump, node, isNode, 4, 5, 3);
        constructGraph(jump, node, isNode, 1, 5, 4);
        constructGraph(jump, node, isNode, 7, 1, 5);
        constructGraph(jump, node, isNode, 9, 1, 6);
        constructGraph(jump, node, isNode, 10, 9, 7);
        constructGraph(jump, node, isNode, 11, 10, 8);
        constructGraph(jump, node, isNode, 6, 10, 9);
        constructGraph(jump, node, isNode, 8, 10, 10);
        // function to pre compute jump matrix
        set_jump_pointer(jump, node, len, n);
        // query to jump to parent using jump pointers
        // query to jump to 1st parent of node 2
        jumpPointer(jump, isNode, 2, 0, n);
        // query to jump to 2nd parent of node 4
        jumpPointer(jump, isNode, 4, 2, n);
        // query to jump to 3rd parent of node 8
        jumpPointer(jump, isNode, 8, 3, n);
        // query to jump to 5th parent of node 20
        jumpPointer(jump, isNode, 20, 5, n);
    };
};