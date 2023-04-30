#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node *head = NULL; //Initialize empty list
void insert(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node)); //Initialize new Node
    newNode->data = value;
    newNode->next = NULL;
    //If list is empty then set new node as first node
    if (head == NULL) { 
        head = newNode;
    }
    //Otherwise add new node at the end of the list 
    else { 
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void printList() {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main() {
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    printf("Danh sách liên kết đơn: ");
    printList();
    return 0;
}