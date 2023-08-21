using System;
class LinkedListNode {
    public int data;
    public LinkedListNode next;
    public LinkedListNode(int value){
        data = value;
        next = null;
    };
};
class LinkedList {
    private LinkedListNode head;
    public LinkedList(){
        head = null;
    };
    public void AddNode(int value){
        LinkedListNode newNode = new LinkedListNode(value);
        if(head == null){
            head = newNode;
        }
        else {
            LinkedListNode currentNode = head;
            while(currentNode.next != null){
                currentNode = currentNode.next;
            };
            currentNode.next = newNode;
        };
    };
    public void RemoveNode(int value){
        if(head == null){
            return;
        }
        if(head.data == value){
            head = head.next;
            return;
        }
        LinkedListNode currentNode = head.next;
        LinkedListNode previousNode = head;
        while(currentNode != null){
            if(currentNode.data == value){
                previousNode.next = currentNode.next;
                return;
            };
            previousNode = currentNode;
            currentNode = currentNode.next;
        };
    };
    public void PrintList(){
        if(head == null){
            Console.WriteLine("LinkedList is empty");
            return;
        }
        LinkedListNode currentNode = head;
        while(currentNode != null){
            Console.Write(currentNode.data + " ");
            currentNode = currentNode.next;
        };
        Console.WriteLine();
    };
};
class Program {
    static void Main(){
        LinkedList myList = new LinkedList();
        for(int i = 0; i < 5; i++){
            myList.AddNode(i);
        };
        myList.PrintList(); // output: 0 1 2 3 4
        myList.RemoveNode(2);
        myList.PrintList(); // output: 0 1 3 4
    };
};