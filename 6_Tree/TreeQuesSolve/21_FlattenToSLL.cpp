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
Node *root, *temp,*ttemp;

void flatten(Node* root) {
    if (root == nullptr) return;
    if (root->left) flatten(root->left);
    if (root->right) flatten(root->right);
    
    temp = root->right;
    root->right = root->left;
    root->left = nullptr;

    ttemp = root;
    while (ttemp->right != nullptr) {
        ttemp = ttemp->right;
    }
    ttemp->right = temp;
}

int main() {
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);

    flatten(root);
    while (root != nullptr) {
        cout << root->data << " ";
        root = root->right;
    }
    return 0;
}