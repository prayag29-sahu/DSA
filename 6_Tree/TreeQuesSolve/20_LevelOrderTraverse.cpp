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

int height(Node *root)
{
    if (root == nullptr)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

void printGivenLevel(Node *root, int level)
{
    if (root == nullptr)
        return;
    if (level == 1)
    {
        cout << root->data << " ";
    }
    else if (level > 1)
    {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}

void levelOrder(Node *root)
{
    int h = height(root);
    for (int i = 1; i <= h; i++)
    {
        printGivenLevel(root, i);
        cout << endl;
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Level Order Traversal of the tree is: " << endl;
    levelOrder(root);

    return 0;
}
