class Edge {
    constructor(start, end, weight){
      this.start = start;
      this.end = end;
      this.weight = weight;
    }
}
class Graph {
    constructor(vertices){
        this.vertices = vertices;
        this.edges = [];
    }
    addEdge(start, end, weight){
        const edge = new Edge(start, end, weight);
        this.edges.push(edge);
    }
    bellmanFord(start){
        const dist = {};
        const prev = {};
        for (let i = 0; i < this.vertices.length; i++){
            dist[this.vertices[i]] = Infinity;
            prev[this.vertices[i]] = null;
        }
        dist[start] = 0;
        for (let i = 0; i < this.vertices.length - 1; i++){
            for (let j = 0; j < this.edges.length; j++){
                const edge = this.edges[j];
                const u = edge.start;
                const v = edge.end;
                const weight = edge.weight;
                if (dist[u] !== Infinity && dist[u] + weight < dist[v]){
                    dist[v] = dist[u] + weight;
                    prev[v] = u;
                }
            }
        }
        return {dist, prev};
    }
}
const vertices = ['A', 'B', 'C', 'D', 'E'];
const graph = new Graph(vertices);
graph.addEdge('A', 'B', 3);
graph.addEdge('A', 'C', 2);
graph.addEdge('B', 'D', 4);
graph.addEdge('B', 'E', 1);
graph.addEdge('C', 'B', 1);
graph.addEdge('C', 'D', 2);
graph.addEdge('D', 'E', 3);
const start = 'A';
const {dist, prev} = graph.bellmanFord(start);
console.log(dist); //{A: 0, B: 3, C: 2, D: 4, E: 4}
console.log(prev); //{A: null, B: 'A', C: 'A', D: 'C', E: 'B'}