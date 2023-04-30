using System;
class BellmanFordShortestPath{
    static void BellmanFord(int[,] graph, int source){
        int verticesCount = graph.GetLength(0);
        int[] dist = new int[verticesCount];
        for (int i = 0; i < verticesCount; ++i)
            dist[i] = int.MaxValue;
        dist[source] = 0;
        for (int i = 0; i < verticesCount - 1; ++i){
            for (int j = 0; j < verticesCount; ++j){
                for (int k = 0; k < verticesCount; ++k){
                    if (graph[j, k] != 0 && dist[j] != int.MaxValue && dist[j] + graph[j, k] < dist[k])
                        dist[k] = dist[j] + graph[j, k];
                }
            }
        }
        //Check if there is a negative cycle  
        for (int j = 0; j < verticesCount; ++j){
            for (int k = 0; k < verticesCount; ++k){
                if (graph[j, k] != 0 && dist[j] != int.MaxValue && dist[j] + graph[j, k] < dist[k]){
                    Console.WriteLine("Đồ thị có chu trình âm");
                    return;
                }
            }
        }
        PrintSolution(dist);
    }
    static void PrintSolution(int[] dist){
        Console.WriteLine("Đỉnh \t Khoảng cách từ nguồn");
        for (int i = 0; i < dist.Length; ++i)
            Console.WriteLine(i + "\t\t" + dist[i]);
    }
    static void Main(string[] args){
        int[,] graph = {
            {0, -1, 4, 0, 0},
            {0, 0, 3, 2, 2},
            {0, 0, 0, 0, 0},
            {0, 1, 5, 0, 0},
            {0, 0, 0, -3, 0}
        };
        BellmanFord(graph, 0);
    }
}