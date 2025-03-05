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

Node *defoliate(Node *root)
{
    if (root == nullptr)
        return nullptr;

    if (root->left == nullptr && root->right == nullptr)
    {
        delete root; 
        return nullptr;
    }

    root->left = defoliate(root->left);
    root->right = defoliate(root->right);

    return root;
}

void inOrder(Node *root)
{
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Original Tree (In-Order Traversal): ";
    inOrder(root);
    cout << endl;

    root = defoliate(root);

    cout << "Tree after Defoliation (In-Order Traversal): ";
    inOrder(root);
    cout << endl;

    return 0;
}
