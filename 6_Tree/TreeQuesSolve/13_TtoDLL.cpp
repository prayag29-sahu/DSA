#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};


void convertToDLL(Node* root, Node*& head, Node*& prev) {
    if (root == nullptr) return;
    convertToDLL(root->left, head, prev);
    
    if (prev == nullptr) head = root; 
    else {
        prev->right = root;
        root->left = prev;
    }
    prev = root;
    convertToDLL(root->right, head, prev);
}

Node* convertBTToDLL(Node* root) {
    Node* head = nullptr;
    Node* prev = nullptr;
    convertToDLL(root, head, prev);
    return head;
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(2);
    root->left->right = new Node(8);

    Node* head = convertBTToDLL(root);
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->right;
    }
    return 0;
}