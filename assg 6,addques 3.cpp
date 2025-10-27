#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int d) {
        data = d;
        prev = next = NULL;
    }
};
Node* reverseKGroup(Node* head, int k) {
    if (!head) return NULL;
    Node* current = head;
    Node* nextNode = NULL;
    Node* prevNode = NULL;
    int count = 0;
    while (current != NULL && count < k) {
        nextNode = current->next;
        current->next = prevNode;
        current->prev = nextNode;  
        prevNode = current;
        current = nextNode;
        count++;
    }
    if (nextNode != NULL) {
        head->next = reverseKGroup(nextNode, k);
        if (head->next != NULL)
            head->next->prev = head;
    }
    return prevNode; 
}
void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->prev = head->next->next->next;
      head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->prev = head->next->next->next->next;
    cout << "Original list: ";
    print(head);
    int k = 2;
    head = reverseKGroup(head, k);
    cout << "Reversed list in groups of " << k << ": ";
    print(head);
    return 0;
}
