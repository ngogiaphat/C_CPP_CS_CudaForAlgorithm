using System;
using System.Collections.Generic;
class Graph {
    private int V; 
    private List<int>[] adj; 
    public Graph(int v){
        V = v;
        adj = new List<int>[v];
        for (int i = 0; i < v; ++i)
            adj[i] = new List<int>();
    }
    public void addEdge(int v, int w){
        adj[v].Add(w);
    }
    public void DFS(int v){
        bool[] visited = new bool[V];
        Stack<int> stack = new Stack<int>();
        visited[v] = true;
        stack.Push(v);
        while (stack.Count != 0){
           
            v = stack.Pop();
            Console.Write(v + " ");
            foreach(int i in adj[v]){
                if(!visited[i]){
                    visited[i] = true;
                    stack.Push(i);
                }
            }
        }
    }
}
class Program {
    static void Main(string[] args){
        Graph g = new Graph(4);
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(2, 3);
        g.addEdge(3, 3);
        Console.WriteLine("DFS traveresal starting from vertex 2:");
        g.DFS(2);
    }
}