#include<string>
#include<bits/stdc++.h>
using namespace std;
int R = 0;
// n -> it represent total number of nodes len -> it is the maximum length of array to hold parent of each node.
// In worst case, the highest value of parent a node can have is n-1.
// 2 ^ len <= n-1
// len = O(log2n)
int getLen(int n){
	int len = (int)(log(n) / log(2)) + 1;
	return len;
};
// jump represent 2D matrix to hold parent of node in jump matrix here we pass reference of 2D matrix so that the change made
// occur directly to the original matrix len is same as defined above
// n is total nodes in graph
void set_jump_pointer(vector<vector<int> >& jump, vector<int> node, int len, int n){
	for(int j = 1; j <= len; j++)
		for(int i = 0; i < n; i++)
			jump[ node[i] ][j] = jump[jump[node[i] ][j - 1] ][j - 1];
};
// c -> it represent child
// p -> it represent parent
// i -> it represent node number
// p=0 means the node is root node
// here also we pass reference of 2D matrix and depth vector so that the change made occur directly to the original matrix and original vector
void constructGraph(vector<vector<int> >& jump, vector<int>& node, vector<int>& isNode, int c, int p, int i){
	// enter the node in node array
	// it stores all the nodes in the graph
	node[i] = c;
	// to confirm that no child node have 2 parents
	if(isNode == 0){
		isNode = 1;
		// make parent of x as y
		jump[0] = p;
	};
	return;
};
// function to jump to Lth parent of any node
void jumpPointer(vector<vector<int> >& jump, vector<int> isNode, int x, int L, int n){
	int j = 0, curr = x, k = L;
	// to check if node is present in graph or not
	if(x > n || isNode[x] == 0) {
		cout << "Node is not present in graph " << endl;
		return;
	};
	// in this loop we decrease the value of L by L/2 and increment j by 1 after each iteration, and check for set bit
	// if we get set bit then we update x with jth parent of x as L becomes less than or equal to zero means we have jumped to Lth parent of node x
	while(L > 0){
		// to check if last bit is 1 or not
		if(L & 1)
			x = jump[x][j];
		// use of shift operator to make
		// L = L/2 after every iteration
		L = L >> 1;
		j++;
	};
	cout << k << "th parent of node " << curr << " is = " << x << endl;
	return;
};
// Driver code
int main(){
	// n represent number of nodes
	int n = 11;
	// function to calculate len
	// len -> it is the maximum length of array to hold parent of each node.
	int len = getLen(n);
	// initialization of parent matrix
	vector<vector<int>> jump(n+1, vector<int>(len+1));
	// node array is used to store all nodes
	vector<int> node(n+1);
	// isNode is an array to check whether a node is present in graph or not
	vector<int> isNode(n+1,0);
	// R stores root node
	R = 2;
	// construction of graph here 0 represent that the node is root node
	constructGraph(jump, node, isNode, 2, 0, 0);
	constructGraph(jump, node, isNode, 5, 2, 1);
	constructGraph(jump, node, isNode, 3, 5, 2);
	constructGraph(jump, node, isNode, 4, 5, 3);
	constructGraph(jump, node, isNode, 1, 5, 4);
	constructGraph(jump, node, isNode, 7, 1, 5);
	constructGraph(jump, node, isNode, 9, 1, 6);
	constructGraph(jump, node, isNode, 10, 9, 7);
	constructGraph(jump, node, isNode, 11, 10, 8);
	constructGraph(jump, node, isNode, 6, 10, 9);
	constructGraph(jump, node, isNode, 8, 10, 10);
	// function to pre compute jump matrix
	set_jump_pointer(jump, node, len, n);
	// query to jump to parent using jump pointers
	// query to jump to 1st parent of node 2
	jumpPointer(jump, isNode, 2, 0, n);
	// query to jump to 2nd parent of node 4
	jumpPointer(jump, isNode, 4, 2, n);
	// query to jump to 3rd parent of node 8
	jumpPointer(jump, isNode, 8, 3, n);
	// query to jump to 5th parent of node 20
	jumpPointer(jump, isNode, 20, 5, n);
	return 0;
};