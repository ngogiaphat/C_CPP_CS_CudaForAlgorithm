#include <iostream>
using namespace std;
//Declare a structure for an element in a singly linked list
struct Node {
    int data;
    Node* next;
};
//Function to print singly linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
//Function that adds an element to the end of a singly linked list
void insertEnd(Node** head, int new_data) {
    Node* new_node = new Node;
    Node* last = *head;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}
//Function main
int main() {
    Node* head = NULL;
    insertEnd(&head, 6);
    insertEnd(&head, 3);
    insertEnd(&head, 8);
    insertEnd(&head, 1);
    cout << "Danh sách liên kết đơn là: ";
    printList(head);
    return 0;
}