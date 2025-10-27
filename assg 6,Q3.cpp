#include <iostream>
using namespace std;
class 	DNode {
public:
    int data;
    DNode* next;
    DNode* prev; 
    DNode(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
class CNode{
	public:
	int data;
	CNode* next;
	CNode(int d){
		this->data=d;
		this->next=next;
	}
};
int sizeDoubly(DNode* head) {
    int count = 0;
    DNode* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
int sizeCircular(CNode* tail) {
    if (tail == NULL)
        return 0;
    int count = 0;
    CNode* temp = tail->next; 
    do {
        count++;
        temp = temp->next;
    } while (temp != tail->next);
    return count;
}
int main() {
    // Doubly Linked List
    DNode* head1 = new DNode(10);
    DNode* second = new DNode(20);
    DNode* third = new DNode(30);
    head1->next = second;
    second->prev = head1;
    second->next = third;
    third->prev = second;
    cout << "Doubly Linked List: ";
    cout << "Size of Doubly Linked List: " << sizeDoubly(head1) << endl;
    // Circular Linked List
    CNode* tail = new CNode(20);
    tail->next = new CNode(100);
    tail->next->next = new CNode(40);
    tail->next->next->next = new CNode(80);
    tail->next->next->next->next = new CNode(60);
    tail->next->next->next->next->next = tail; 
    cout << "\nCircular Linked List: ";
    cout << "Size of Circular Linked List: " << sizeCircular(tail) << endl;
    return 0;
}
