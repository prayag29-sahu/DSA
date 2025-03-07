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

Node *LCA(Node *root, int n1, int n2)
{
    if (root == nullptr)
        return nullptr;
    if (root->data == n1 || root->data == n2)
        return root;
    Node *leftLCA = LCA(root->left, n1, n2);
    Node *rightLCA = LCA(root->right, n1, n2);
    if (leftLCA != nullptr && rightLCA != nullptr)
        return root;
    // cout << leftLCA->data << " " << rightLCA->data;
    return (leftLCA != nullptr) ? leftLCA : rightLCA;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Node *lca = LCA(root, 4, 3);
    // cout << lca->data;
    if (lca != nullptr)
        cout << "LCA of 4 and 3 is " << lca->data;
    else
        cout << "LCA not found";
    return 0;
}
