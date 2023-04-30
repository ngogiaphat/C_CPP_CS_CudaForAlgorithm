#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;
//Declaring infinitely
const int INF = numeric_limits<int>::max();  
//Define the structure of a vertex
struct Vertex {
    int id; //ID of vertex
    int distance; //Distance from start vertex to current vertex 
    bool visited; //Reviewed or not? 
    vector<pair<int, int>> edges; //List of edges connected to this vertex 
};
//Define comparison function to use in priority_queue
struct CompareVertex {
    bool operator() (const Vertex& lhs, const Vertex& rhs) const {
        return lhs.distance > rhs.distance;
    }
};

//The function to find the shortest path from the starting vertex to the ending vertex 
vector<int> find_shortest_path(const vector<Vertex>& graph, int start, int end) 
{
    //Initialize the distance of all vertices to infinity (INF)
    vector<int> distance(graph.size(), INF);
    //Initialize the vector storing the shortest path 
    vector<int> path;
    //Initialize a priority queue to store vertices in order of increasing distance 
    priority_queue<Vertex, vector<Vertex>, CompareVertex> pq;
    //Initialization of the vertex starts 
    Vertex start_vertex = graph[start];
    start_vertex.distance = 0;
    start_vertex.visited = true;
    //Put the starting vertex in the priority queue 
    pq.push(start_vertex);
    //Start finding the shortest path
    while (!pq.empty()) {
        //Get the vertex with the shortest distance from the priority queue 
        Vertex current_vertex = pq.top();
        pq.pop();
        //Check if the current vertex is the end vertex 
        if (current_vertex.id == end) {
            //If true, returns the shortest path from the start vertex to the end vertex 
            int parent = current_vertex.id;
            while (parent != start) {
                path.push_back(parent);
                parent = distance[parent];
            }
            path.push_back(parent);
            reverse(path.begin(), path.end());
            break;
        }
        //Iterate over the vertices adjacent to the current vertex 
        for (auto edge : current_vertex.edges) {
            int next_vertex_id
            std::priority_queue<Node, std::vector<Node>, cmp> pq;
            pq.push(Node(s, 0));
            while (!pq.empty()) {
                Node node = pq.top();
                pq.pop();
                int u = node.index, du = node.dist;
                if (du != d[u])
                    continue;
                for (int i = 0; i < graph[u].size(); i++) {
                    Edge e = graph[u][i];
                    int v = e.to;
                    if (d[v] > d[u] + e.w) {
                        d[v] = d[u] + e.w;
                        pq.push(Node(v, d[v]));
                    }
                }
            }
            return d;
        }
    }
}
int main() {
    int n, m, s;
    std::cin >> n >> m >> s;
    std::vector<std::vector<Edge>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        graph[u].push_back(Edge(v, w));
    }
    std::vector<int> d = dijkstra(graph, s);
    for (int i = 0; i < n; i++)
        std::cout << d[i] << " ";
    std::cout << std::endl;
    return 0;
}