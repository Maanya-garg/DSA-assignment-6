#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int d) {
        data = d;
        next = NULL;
        prev = NULL;
    }
};
bool isPalindrome(Node* head) {
    if (head == NULL || head->next == NULL)
        return true;
    Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    while (head != tail && tail->next != head) {
        if (head->data != tail->data)
            return false;
        head = head->next;
        tail = tail->prev;
    }
    return true;
}
int main() {
    Node* head = new Node(1);
    Node* second = new Node(0);
    Node* third = new Node(2);
    Node* fourth = new Node(0);
    Node* fifth = new Node(1);
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    fourth->next = fifth;
    fifth->prev = fourth;
    if (isPalindrome(head)) {
        cout << "It is a palindrome";
    } else {
        cout << "It is not a palindrome";
    }
    return 0;
}
