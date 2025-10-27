#include<iostream>
using namespace std;
class Node{
	public:
	int data;
	Node* next;
	Node(int d){
		this->data=d;
		this->next=next;
	}
};
void print(Node* tail){
    if(tail == NULL) { 
    cout<<"list is empty";
    return;
	} 
	else{
    Node* temp = tail->next;  // start from head
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while(temp != tail->next);
    cout<<temp->data;
    cout << endl;} 
}
int main(){
	 Node* n1 = new Node(20);
    Node* n2 = new Node(100);
    Node* n3 = new Node(40);
    Node* n4 = new Node(80);
    Node* n5 = new Node(60);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n1;  // circular link
    Node* tail = n5; // tail pointing to last node
    cout << "Circular Linked List: ";
    print(tail);
    return 0;
}
