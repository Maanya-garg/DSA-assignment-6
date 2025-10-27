#include <iostream>
using namespace std;
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
int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += (n & 1);
        n >>= 1;
    }
    return count;
}
void printDoubly(DNode* head) {
    if (!head) {
        cout << "List is empty\n";
        return;
    }
    DNode* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
DNode* deleteEvenBitSumNodes(DNode*& head, DNode*& tail) {
    if (!head) {
        cout << "List is empty\n";
        return NULL;
    }
    DNode* temp = head;
    while (temp) {
        int bitSum = countSetBits(temp->data);
        DNode* nextNode = temp->next;

        if (bitSum % 2 == 0) {  
            if (temp == head)
                head = temp->next;
            if (temp == tail)
                tail = temp->prev;
            if (temp->next)
                temp->next->prev = temp->prev;
            if (temp->prev)
                temp->prev->next = temp->next;
            delete temp;
        }
        temp = nextNode;
    }
    return head;
}
class CNode {
public:
    int data;
    CNode* next;
    CNode(int d) {
        data = d;
        next = NULL;
    }
};

void printCircular(CNode* tail) {
    if (!tail) {
        cout << "list is empty\n";
        return;
    }
    CNode* temp = tail->next;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << endl;
}

CNode* deleteEvenBitSumNodesCLL(CNode*& tail) {
    if (!tail) {
        cout << "List is empty\n";
        return NULL;
    }

    CNode* curr = tail->next;
    CNode* prev = tail;
    CNode* head = tail->next;

    bool changed = true;
    while (changed) {
        changed = false;
        int nodes = 0;
        CNode* temp = tail->next;
        do { nodes++; temp = temp->next; } while (temp != tail->next);
        for (int i = 0; i < nodes; i++) {
            int bitSum = countSetBits(curr->data);
            if (bitSum % 2 == 0) {  
                if (curr == prev) {
                    delete curr;
                    tail = NULL;
                    return NULL;
                }
                prev->next = curr->next;
                if (curr == tail)
                    tail = prev;
                if (curr == head)
                    head = curr->next;
                delete curr;
                curr = prev->next;
                changed = true;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
    }
    return tail;
}

int main() {
   
    DNode* head1 = new DNode(18);
    DNode* second = new DNode(15);
    DNode* third = new DNode(8);
    DNode* fourth = new DNode(9);
    DNode* fifth = new DNode(14);
    head1->next = second;
    second->prev = head1;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    fourth->next = fifth;
    fifth->prev = fourth;
    DNode* tail1 = fifth;
    cout << "Original Doubly Linked List: ";
    printDoubly(head1);
    deleteEvenBitSumNodes(head1, tail1);
    cout << "After deleting even-bit-sum nodes (DLL): ";
    printDoubly(head1);

    CNode* n1 = new CNode(9);
    CNode* n2 = new CNode(11);
    CNode* n3 = new CNode(34);
    CNode* n4 = new CNode(6);
    CNode* n5 = new CNode(13);
    CNode* n6 = new CNode(21);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n1;
    CNode* tail2 = n6;

    cout << "\nOriginal Circular Linked List: ";
    printCircular(tail2);

    deleteEvenBitSumNodesCLL(tail2);

    cout << "After deleting even-bit-sum nodes (CLL): ";
    printCircular(tail2);

    return 0;
}

