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

int diameter(Node *root, int &maxDiameter)
{
    if (root == nullptr)
        return 0;
    int lh = diameter(root->left, maxDiameter);
    int rh = diameter(root->right, maxDiameter);
    maxDiameter = max(maxDiameter, lh + rh);
    return 1 + max(lh, rh);
}

int getDiameter(Node *root)
{
    int maxDiameter = 0;
    return diameter(root, maxDiameter);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    // root->left->left->left = new Node(6);

    cout << "Diameter of tree: " << getDiameter(root);
    return 0;
}
