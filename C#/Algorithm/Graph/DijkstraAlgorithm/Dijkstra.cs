using System;
using System.Collections.Generic;
public class DijkstraAlgorithm {
    public void Dijkstra(int[,] graph, int startNode){
        int nodesCount = graph.GetLength(0);
        int[] distance = new int[nodesCount];
        bool[] visited = new bool[nodesCount];
        for(int i = 0; i < nodesCount; ++i){
            distance[i] = int.MaxValue;
            visited[i] = false;
        }
        distance[startNode] = 0;
        for(int i = 0; i < nodesCount - 1; ++i){
            int currentNode = FindNextNodeWithMinDistance(distance, visited);
            if(currentNode == -1) break;
            visited[currentNode] = true;
            for(int j = 0; j < nodesCount; ++j){
                if(graph[currentNode, j] > 0 && !visited[j]){
                    int newDistance = distance[currentNode] + graph[currentNode, j];
                    if(newDistance < distance[j]){
                        distance[j] = newDistance;
                    }
                }
            }
        }
        PrintResult(distance);
    }
    private int FindNextNodeWithMinDistance(int[] distance, bool[] visited){
        int minDistance = int.MaxValue;
        int minNode = -1;
        for(int i = 0; i < distance.Length; ++i){
            if(!visited[i] && distance[i] < minDistance){
                minDistance = distance[i];
                minNode = i;
            }
        }
        return minNode;
    }
    private void PrintResult(int[] distance){
        Console.WriteLine("Vertex Distance from Start Node");
        for(int i = 0; i < distance.Length; ++i){
            Console.WriteLine("{0} \t\t {1}", i, distance[i]);
        }
    }
}
class Program {
    static void Main(string[] args){
        int[,] graph = new int[,]{
            {0, 1, 4, 0, 0},
            {1, 0, 2, 5, 0},
            {4, 2, 0, 1, 3},
            {0, 5, 1, 0, 2},
            {0, 0, 3, 2, 0},
        };
        DijkstraAlgorithm dijkstra = new DijkstraAlgorithm();
        dijkstra.Dijkstra(graph, 0);
    }
}