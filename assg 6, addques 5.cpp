#include <iostream>
using namespace std;
class Node {
    int data;
    Node *right, *down, *left, *up;
    Node(int x) {
        data = x;
        right = down = left = up = NULL;
    }
};
Node* constructLinkedMatrix(int mat[][3], int n, int m) {
    Node* node[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            node[i][j] = new Node(mat[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // right pointer
            if (j + 1 < m)
                node[i][j]->right = node[i][j + 1];
            // left pointer
            if (j - 1 >= 0)
                node[i][j]->left = node[i][j - 1];
            // down pointer
            if (i + 1 < n)
                node[i][j]->down = node[i + 1][j];
            // up pointer
            if (i - 1 >= 0)
                node[i][j]->up = node[i - 1][j];
        }
    }
    return node[0][0];
}
void printList(Node* head) {
    Node* downPtr = head;
    while (downPtr) {
        Node* rightPtr = downPtr;
        while (rightPtr) {
            cout << rightPtr->data << " ";
            rightPtr = rightPtr->right;
        }
        cout << endl;
        downPtr = downPtr->down;
    }
}
int main() {
    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int n = 3, m = 3;
    Node* head = constructLinkedMatrix(mat, n, m);
    cout << "Linked Matrix Representation:\n";
    printList(head);
    return 0;
}
