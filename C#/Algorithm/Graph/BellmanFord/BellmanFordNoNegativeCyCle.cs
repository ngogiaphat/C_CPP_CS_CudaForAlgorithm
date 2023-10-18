using System;
class BellmanFordShortestPath {
    static void BellmanFord(int[,] graph, int source){
        int verticesCount = graph.GetLength(0);
        int[] dist = new int[verticesCount];
        for(int i = 0; i < verticesCount; ++i){
            dist[i] = int.MaxValue;
        }
        dist[source] = 0;
        for(int i = 0; i < verticesCount - 1; ++i){
            for(int j = 0; j < verticesCount; ++j){
                for(int k = 0; k < verticesCount; ++k){
                    if(graph[j, k] != 0 && dist[j] != int.MaxValue && dist[j] + graph[j, k] < dist[k]){
                        dist[k] = dist[j] + graph[j, k];
                    }
                }
            }
        }
        PrintSolution(dist);
    }
    static void PrintSolution(int[] dist){
        Console.WriteLine("Vertex \t Distance from Source");
        for(int i = 0; i < dist.Length; ++i){
            Console.WriteLine(i + "\t\t" + dist[i]);
        }
    }
    static void Main(string[] args){
        int[,] graph = {
            {0, 4, 0, 0, 0, 0, 0, 8, 0},
            {4, 0, 8, 0, 0, 0, 0, 11, 0},
            {0, 8, 0, 7, 0, 4, 0, 0, 2},
            {0, 0, 7, 0, 9, 14, 0, 0, 0},
            {0, 0, 0, 9, 0, 10, 0, 0, 0},
            {0, 0, 4, 14, 10, 0, 2, 0, 0},
            {0, 0, 0, 0, 0, 2, 0, 1, 6},
            {8, 11, 0, 0, 0, 0, 1, 0, 7},
            {0, 0, 2, 0, 0, 0, 6, 7, 0}
        };
        BellmanFord(graph, 0);
    }
}