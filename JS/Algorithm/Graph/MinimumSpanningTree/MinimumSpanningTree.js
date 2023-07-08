class Graph {
	constructor(vertices){
		this.V = vertices;
		this.graph = new Array(vertices);
		for(let i = 0; i < vertices; ++i){
			this.graph[i] = new Array(vertices).fill(0);
		}
	}
	addEdge(u, v, weight){
		this.graph[u][v] = weight;
		this.graph[v][u] = weight;
	}
	minKey(key, mstSet){
		let min = Number.POSITIVE_INFINITY;
		let minIndex = -1;
		for (let v = 0; v < this.V; ++v){
			if (mstSet[v] == false && key[v] < min){
				min = key[v];
				minIndex = v;
			}
		}
		return minIndex;
	}
	primMST(){
		let parent = new Array(this.V);
		let key = new Array(this.V);
		let mstSet = new Array(this.V);
		for(let i = 0; i < this.V; ++i){
			key[i] = Number.POSITIVE_INFINITY;
			mstSet[i] = false;
		}
		key[0] = 0;
		parent[0] = -1;
		for(let count = 0; count < this.V - 1; ++count){
			let u = this.minKey(key, mstSet);
			mstSet[u] = true;
			for(let v = 0; v < this.V; ++v){
				if(this.graph[u][v] && mstSet[v] == false && this.graph[u][v] < key[v]){
					parent[v] = u;
					key[v] = this.graph[u][v];
				}
			}
		}
		return parent;
	}
}
//Example usage
const g = new Graph(5);
g.addEdge(0, 1, 2);
g.addEdge(0, 3, 6);
g.addEdge(1, 2, 3);
g.addEdge(1, 3, 8);
g.addEdge(1, 4, 5);
g.addEdge(2, 4, 7);
g.addEdge(3, 4, 9);
const parent = g.primMST();
console.log("Edge \tWeight");
for (let i = 1; i < g.V; ++i){
	console.log(parent[i] + " - " + i + "\t" + g.graph[i][parent[i]]);
}