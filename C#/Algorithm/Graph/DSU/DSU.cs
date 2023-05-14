using System;
class DSU {
    static int[] parent;
    static void Main(){
        int n = 10;
        MakeSet(n);
        Union(1, 2);
        Union(3, 4);
        Union(1, 4);
        Console.WriteLine(FindParent(2)); // Output: 4
        Console.WriteLine(FindParent(3)); // Output: 4
    }
    static void MakeSet(int n){
        parent = new int[n];
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }
    static int FindParent(int node){
        if(parent[node] == node){
            return node;
        }
        parent[node] = FindParent(parent[node]);
        return parent[node];
    }
    static void Union(int x, int y){
        int x_set = FindParent(x);
        int y_set = FindParent(y);
        parent[x_set] = y_set;
    }
}