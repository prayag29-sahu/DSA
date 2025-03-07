#include <iostream>
#include <climits> // For INT_MIN and INT_MAX
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

bool IsBST(Node* root, int min, int max) {
    if (root == nullptr)
        return true;
    if (root->data < min || root->data > max) return false;
    return IsBST(root->left, min, root->data - 1) &&
           IsBST(root->right, root->data + 1, max);
}

bool isBST(Node* root) {
    return IsBST(root, INT_MIN, INT_MAX);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(2);
    root->left->right = new Node(4);

    cout << (isBST(root) ? "The tree is a BST" : "The tree is not a BST");
    return 0;
}