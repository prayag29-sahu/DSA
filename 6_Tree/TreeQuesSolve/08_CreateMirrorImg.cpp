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

void mirror(Node *root)
{
    if (root == nullptr)
        return;

    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

void inOrder(Node *node)
{
    inOrder(node->left);

    cout << node->data << " ";

    inOrder(node->right);
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

    cout << "In-order Traversal of Original Tree: ";
    inOrder(root);

    mirror(root);
    cout << "In-order Traversal of Mirrored Tree: ";
    inOrder(root);
    cout << endl;

    return 0;
}
