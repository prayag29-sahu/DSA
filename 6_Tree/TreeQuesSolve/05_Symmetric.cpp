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

int isMirror(Node *leftSubtree, Node *rightSubtree)
{
    if (leftSubtree == nullptr && rightSubtree == nullptr)
        return 1;
    if (leftSubtree == nullptr || rightSubtree == nullptr)
        return 0;

    return (leftSubtree->data == rightSubtree->data) &&
        isMirror(leftSubtree->left, rightSubtree->right) &&
        isMirror(leftSubtree->right, rightSubtree->left);
}

int isSymmetric(Node *root)
{
    if (root == nullptr)
        return true;

    return isMirror(root->left, root->right);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    if (isSymmetric(root))
        cout << "The tree is Symmetric." << endl;
    else
        cout << "The tree is NOT Symmetric." << endl;

    return 0;
}
