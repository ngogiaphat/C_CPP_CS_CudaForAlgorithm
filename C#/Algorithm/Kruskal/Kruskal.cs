using System;
using System.Collections.Generic;
using System.Linq;
class KruskalMst{
    class Edge{
        public int U, V, W;
    }
    static int Find(int[] parent, int i){
        if (parent[i] == i)
            return i;
        return parent[i] = Find(parent, parent[i]);
    }
    static void Union(int[] parent, int[] rank, int x, int y){
        int xroot = Find(parent, x);
        int yroot = Find(parent, y);
        if (rank[xroot] < rank[rootY])
            parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else{
            parent[rootX] = rootY;
            rank[rootY]++;
        }
    }
    static List<Edge> Kruksal(List<Edge> edges, int n){
        var mst = new List<Edge>();
        var parent = new int[n];
        var rank = new int[n];
        for(int i = 0; i < n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
        edges.Sort((e1, e2) => e1.W.CompareTo(e2.W));
        int cnt = 0;
        foreach(var edge in edges){
            int u = edge.U, v = edge.V, w = edge.W;
            if(Find(parent, u) != Find(parent, v)){
                Union(parent, rank, u, v);
                mst.Add(edge);
                cnt++;
            }
            if(cnt == n - 1)
                break;
        }
        return mst;
    }
    static void Main(){
        int n = 6;
        var edges = new List<Edge>(){
            new Edge(){U = 0, V = 1, W = 2},
            new Edge(){U = 0, V = 2, W = 3},
            new Edge(){U = 1, V = 2, W = 1},
            new Edge(){U = 1, V = 3, W = 2},
            new Edge(){U = 2, V = 3, W = 4},
        };
        var mst = Kruksal(edges, n);
        foreach(var edge in mst)
            Console.WriteLine($"{edge.U} {edge.V} {edge.W}");
    }
}