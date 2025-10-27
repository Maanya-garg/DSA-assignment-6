#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* prev; 
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
int sizeDoubly(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
int sizeCircular(Node* tail) {
    if (tail == NULL)
        return 0;
    int count = 0;
    Node* temp = tail->next; 
    do {
        count++;
        temp = temp->next;
    } while (temp != tail->next);
    return count;
}
int main() {
    // Doubly Linked List
    Node* head1 = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    head1->next = second;
    second->prev = head1;
    second->next = third;
    third->prev = second;
    cout << "Doubly Linked List: ";
    cout << "Size of Doubly Linked List: " << sizeDoubly(head1) << endl;
    // Circular Linked List
    Node* tail = new Node(20);
    tail->next = new Node(100);
    tail->next->next = new Node(40);
    tail->next->next->next = new Node(80);
    tail->next->next->next->next = new Node(60);
    tail->next->next->next->next->next = tail; 
    cout << "\nCircular Linked List: ";
    cout << "Size of Circular Linked List: " << sizeCircular(tail) << endl;
    return 0;
}
