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

int countNodes(Node *root)
{
    if (root == nullptr)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

bool isCBT(Node *root, int i, int nodeCount)
{
    if (root == nullptr)
        return true;

    if (i >= nodeCount)
        return false;

    bool left = isCBT(root->left, 2 * i + 1, nodeCount);
    bool right = isCBT(root->right, 2 * i + 2, nodeCount);

    return left && right;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    int nodeCount = countNodes(root);
    int index = 0;

    if (isCBT(root, index, nodeCount))
        cout << "The tree is a Complete Binary Tree." << endl;
    else
        cout << "The tree is NOT a Complete Binary Tree." << endl;

    return 0;
}
