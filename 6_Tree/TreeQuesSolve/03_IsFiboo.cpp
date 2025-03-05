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

bool isFibT(Node *root)
{

    if (root == nullptr)
        return true;

    if (root->left == nullptr && root->right == nullptr)
    {
        return root->data == 1;
    }

    int leftData = (root->left != nullptr) ? root->left->data : 0;
    int rightData = (root->right != nullptr) ? root->right->data : 0;

    bool isFibNode = (root->data == leftData + rightData);

    return isFibNode && isFibT(root->left) && isFibT(root->right);
}

int main()
{

    Node *root = new Node(3);
    root->left = new Node(2);
    root->right = new Node(1);
    root->left->left = new Node(1);
    root->left->right = new Node(1);
    root->right->right = new Node(1);

    if (isFibT(root))
        cout << "The tree is a Fibonacci Tree." << endl;
    else
        cout << "The tree is NOT a Fibonacci Tree." << endl;

    return 0;
}
