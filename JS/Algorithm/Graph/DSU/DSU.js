class DSU {
  constructor(n){
    this.parent = new Array(n);
    for (let i=0; i<n; i++){
      this.parent[i] = i;
    }
  }
  find(x){
    if (this.parent[x] !== x){
      this.parent[x] = this.find(this.parent[x]);
    }
    return this.parent[x];
  }
  union(x, y){
    const rootX = this.find(x);
    const rootY = this.find(y);
    if (rootX !== rootY){
      this.parent[rootX] = rootY;
    }
  }
}
//Using DSU to combine 2 sets
const dsu = new DSU(5);
dsu.union(0, 1);
dsu.union(1, 2);
dsu.union(3, 4);
if(dsu.find(1) === dsu.find(2)){
  console.log("Các phần tử 0, 1, 2 là 1 tập hợp");
}
if(dsu.find(2) !== dsu.find(3)){
  console.log("Các phần tử 2 và 3 không thuộc cùng tập hợp");
}