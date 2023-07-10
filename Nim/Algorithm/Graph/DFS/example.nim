type Graph = seq[seq[int]]
proc dethFirstSearch(graph: Graph, startNode: int, visited: var seq[bool]) = echo startNode 
    visited[startNode] = true
    for i in 0..graph[startNode].len-1:
        let neighbour = graph[startNode][i]
        if not visited[neighbour]:
            dethFirstSearch(graph, neighbour, visited)
var graph: Graph = @[
    @[1], 
    @[2],
    @[1, 2],
    @[0, 2, 3],
    @[0, 1, 4],
]
var visited: seq[bool] = seq[bool](graph.len, false)
dethFirstSearch(graph, 0, visited)