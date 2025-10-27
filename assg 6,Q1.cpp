#include <iostream>
using namespace std;
//Doubly linked list
class DNode {
public:
    int data;
    DNode* prev;
    DNode* next;
    DNode(int d) {
        data = d;
        prev = next = NULL;
    }
};
void printDoubly(DNode* head){
	DNode* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
void insertAtHead(DNode* &head,DNode* &tail, int data){
	if (head==NULL){
		DNode* temp=new DNode(data);
		head=temp;
		tail=temp;
	}
	else{
			DNode* temp=new DNode(data);
	temp->next=head;
	head->prev=temp;
	head=temp;
	}
}
void insertAtTail(DNode* &head,DNode* &tail, int data){
		if (tail==NULL){
		DNode* temp=new DNode(data);
		tail=temp;
		head=temp;
	}
	else{
		DNode* temp=new DNode(data);
	DNode* tail=head;
	while(tail->next!=0){
		tail=tail->next;
	}
	tail->next=temp;
	temp->prev=tail;
	temp->next=NULL;
	tail=temp;
	}
}
void insertAfterValue(DNode*& head, DNode*& tail, int value, int data) {
    DNode* temp = head;
    while (temp && temp->data != value)
        temp = temp->next;
    if (!temp) {
        cout << "Value not found!\n";
        return;
    }
    DNode* newNode = new DNode(data);
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next)
        temp->next->prev = newNode;
    else
        tail = newNode; 
    temp->next = newNode;
}
void deleteNode(DNode*& head, DNode*& tail, int value) {
    if (!head) {
        cout << "List is empty\n";
        return;
    }
    DNode* temp = head;
    while (temp && temp->data != value)
        temp = temp->next;
    if (!temp) {
        cout << "Node not found\n";
        return;
    }
    if (temp == head)
        head = head->next;
    if (temp == tail)
        tail = tail->prev;
    if (temp->next)
        temp->next->prev = temp->prev;
    if (temp->prev)
        temp->prev->next = temp->next;
    delete temp;
    cout << "Node " << value << " deleted.\n";
}
void searchDoubly(DNode* head, int value) {
    int pos = 1;
    while (head) {
        if (head->data == value) {
            cout << "Found at position " << pos << endl;
            return;
        }
        head = head->next;
        pos++;
    }
    cout << "Not found\n";
}
//Circular Linked list
class CNode {
public:
    int data;
    CNode* next;
    CNode(int d) {
        data = d;
        next = NULL;
    }
};
void printCircular(CNode* tail){
    if(tail == NULL) { 
    cout<<"list is empty";
    return;
	} 
	else{
    CNode* temp = tail->next;  // start from head
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while(temp != tail->next);
    cout << endl;} 
}
void insertCircular(CNode*& tail, int element, int data) {
    // empty list
    if (!tail) {
        CNode* newNode = new CNode(data);
        tail = newNode;
        newNode->next = newNode;
        return;
    }
    CNode* curr = tail->next;
    while (curr->data != element && curr != tail)
        curr = curr->next;
    CNode* newNode = new CNode(data);
    newNode->next = curr->next;
    curr->next = newNode;
    if (curr == tail)
        tail = newNode;
}
void deleteCircular(CNode*& tail, int value) {
    if (!tail) {
        cout << "List is empty\n";
        return;
    }
    CNode* prev = tail;
    CNode* curr = prev->next;
    while (curr->data != value && curr != tail) {
        prev = curr;
        curr = curr->next;
    }
    if (curr->data != value) {
        cout << "Node not found\n";
        return;
    }
    prev->next = curr->next;
    if (curr == prev)
        tail = NULL;
    else if (curr == tail)
        tail = prev;
    delete curr;
    cout << "Node " << value << " deleted.\n";
}
void searchCircular(CNode* tail, int value) {
    if (!tail) {
        cout << "List is empty\n";
        return;
    }
    CNode* temp = tail->next;
    int pos = 1;
    do {
        if (temp->data == value) {
            cout << "Found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != tail->next);
    cout << "Not found\n";
}
int main() {
    DNode *dHead = NULL, *dTail = NULL;
    CNode* cTail = NULL;
    int choice, listType;
    cout << "Choose List Type:\n1. Doubly Linked List\n2. Circular Linked List\n";
    cin >> listType;
    do {
        cout << "\n------ MENU ------\n";
        cout << "1. Insert Node\n";
        cout << "2. Delete Node\n";
        cout << "3. Search Node\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        if (listType == 1) {
            int data, value;
            switch (choice) {
                case 1:
                    cout << "Enter value to insert: ";
                    cin >> data;
                    cout << "1. At Head  2. At Tail  3. After Specific Value: ";
                    int pos;
                    cin >> pos;
                    if (pos == 1)
                        insertAtHead(dHead, dTail, data);
                    else if (pos == 2)
                        insertAtTail(dHead, dTail, data);
                    else {
                        cout << "Insert after which value? ";
                        cin >> value;
                        insertAfterValue(dHead, dTail, value, data);
                    }
                    break;
                case 2:
                    cout << "Enter value to delete: ";
                    cin >> data;
                    deleteNode(dHead, dTail, data);
                    break;
                case 3:
                    cout << "Enter value to search: ";
                    cin >> data;
                    searchDoubly(dHead, data);
                    break;
                case 4:
                    printDoubly(dHead);
                    break;
            }
        } else if (listType == 2) {
            int data, value;
            switch (choice) {
                case 1:
                    cout << "Enter value to insert: ";
                    cin >> data;
                    cout << "Enter element after which to insert (ignored if empty): ";
                    cin >> value;
                    insertCircular(cTail, value, data);
                    break;
                case 2:
                    cout << "Enter value to delete: ";
                    cin >> data;
                    deleteCircular(cTail, data);
                    break;
                case 3:
                    cout << "Enter value to search: ";
                    cin >> data;
                    searchCircular(cTail, data);
                    break;
                case 4:
                    printCircular(cTail);
                    break;
            }
        }
    } while (choice != 5);
    cout << "Exiting program.\n";
    return 0;
}

