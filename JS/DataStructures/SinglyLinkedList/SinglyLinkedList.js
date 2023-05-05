class Node {
    constructor(data){
      this.data = data;
      this.next = null;
    }
}
class LinkedList {
    constructor(){
        this.head = null;
        this.tail = null;
        this.length = 0;
    }
    add(data){
        const node = new Node(data);
        if(!this.head){
        this.head = node;
        this.tail = node;
        } else {
        this.tail.next = node;
        this.tail = node;
        }
        this.length++;
        return node;
    }
    remove(data){
        if(!this.head){
        return null;
        }   
        let deletedNode = null;
        if (this.head.data === data){
        deletedNode = this.head;
        if (this.head === this.tail){
            this.head = null;
            this.tail = null;
        } 
        else {
            this.head = this.head.next;
        }
        } 
        else {
        let currentNode = this.head;
        while (currentNode.next && currentNode.next.data !== data){
            currentNode = currentNode.next;
        }
        if (currentNode.next && currentNode.next.data === data){
            deletedNode = currentNode.next;

            if (deletedNode === this.tail){
            this.tail = currentNode;
            }
            currentNode.next = currentNode.next.next;
        }
        }
        this.length--;
        return deletedNode;
    }
    get(index){
        if (index < 0 || index >= this.length){
        return null;
        }
        let currentNode = this.head;
        for (let i = 0; i < index; i++){
        currentNode = currentNode.next;
        }
        return currentNode;
    }
    toArray(){
        const nodes = [];
        let currentNode = this.head;
        while (currentNode){
        nodes.push(currentNode);
        currentNode = currentNode.next;
        }
        return nodes;
    }
}
const linkedList = new LinkedList();
linkedList.add('A');
linkedList.add('B');
linkedList.add('C');
console.log(linkedList.toArray());
linkedList.remove('B'); 
console.log(linkedList.toArray());
console.log(linkedList.get(1).data);