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
	~Node(){ //or maybe not even keep it 
		int val=this->data;
		cout<<"memory free for node with data"<<val<<endl;
	}
};
void insertnode(Node*&tail,int element,int d){ //insert after element 
//assuming that the element is in the list
//empty list
if(tail==NULL){
	Node* newnode=new Node(d);
	tail=newnode;
	newnode->next=tail;
} 
else{
		Node* newnode=new Node(d);
		Node*current=tail;
		while(current->data!=element){
			current=current->next;
		}
		newnode->next=current->next;
		current->next=newnode;
		if (current == tail) {  //if newnode added after tail
        tail = newnode;
    }
}}
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
    cout << endl;} 
}
bool isCircular(Node* head){
	if (head==NULL){
		return true;
	}
		Node*temp=head->next;
		while(temp!=NULL && temp!=head){
			temp=temp->next;
		}
		if(temp==head){
			return true;
		}
		return false;
}
int main(){
	Node* tail=NULL;
	//empty list insertion
	insertnode(tail,5,2); //element wont matter as inserting in empty list
	insertnode(tail,2,4);
	insertnode(tail,4,6);
	insertnode(tail,6,7);
	insertnode(tail,7,5);
	if(isCircular(tail)){
		cout<<"Linked list is circular in nature";
	}
	else{
		cout<<"linked list is not circular";
	}
}
