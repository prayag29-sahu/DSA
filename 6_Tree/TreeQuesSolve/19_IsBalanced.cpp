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

bool isBalanced(Node *root, int &height)
{
    if (root == nullptr)
    {
        height = 0;
        return true;
    }
    int lh = 0, rh = 0;
    bool leftBalanced = isBalanced(root->left, lh);
    bool rightBalanced = isBalanced(root->right, rh);
    // height = 1 + max(lh, rh);
    cout << lh<<" "<<rh<<" ";
    return leftBalanced && rightBalanced && (abs(lh - rh) <= 1);
}

bool checkBalanced(Node *root)
{
    int height = 0;
    return isBalanced(root, height);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Is the tree balanced ? : " << (checkBalanced(root) ? "Yes" : "No");
    return 0;
}
