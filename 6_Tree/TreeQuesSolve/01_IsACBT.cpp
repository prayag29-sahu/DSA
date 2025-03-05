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

int isACBTLR(Node *root, int i, int nodeCount)
{
    if (root == nullptr)
        return 1;

    if (i >= nodeCount)
        return 0;

    bool leftCheck = isACBTLR(root->left, 2 * i + 1, nodeCount);
    bool rightCheck = isACBTLR(root->right, 2 * i + 2, nodeCount);

    return leftCheck && rightCheck;
}

int isACBT(Node *root)
{
    int nodeCount = countNodes(root);

    return isACBTLR(root, 0, nodeCount);
}

int main()
{

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    

    if (isACBT(root))
    {
        cout << "The tree is an Almost Complete Binary Tree (ACBT)." << endl;
    }
    else
    {
        cout << "The tree is NOT an Almost Complete Binary Tree (ACBT)." << endl;
    }

    return 0;
}
