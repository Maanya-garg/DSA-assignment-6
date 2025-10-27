#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        this->data = d;
        this->next = NULL;
    }
};
void print(Node* tail) {
    if (tail == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = tail->next;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << endl;
}
Node* splitCircularList(Node* tail) {
    if (tail == NULL || tail->next == tail)
        return tail;  
    int count = 0;
    Node* temp = tail->next;
    do {
        count++;
        temp = temp->next;
    } while (temp != tail->next);
    int mid = (count % 2 == 0) ? (count / 2) : (count / 2 + 1);
    Node* curr = tail->next; 
    for (int i = 1; i < mid; i++) {
        curr = curr->next;
    }
    Node* head1 = tail->next;   
    Node* head2 = curr->next;   
    Node* tail1 = curr;        
    Node* tail2 = tail;        
    tail1->next = head1;
    tail2->next = head2;
    cout << "First half: ";
    print(tail1);
    cout << "Second half: ";
    print(tail2);
    return tail1; 
}
int main() {
    Node* temp1 = new Node(10);
    Node* temp2 = new Node(4);
    Node* temp3 = new Node(9);
    temp1->next = temp2;
    temp2->next = temp3;
    temp3->next = temp1;
    Node* tail=temp3;
    splitCircularList(tail);
}
