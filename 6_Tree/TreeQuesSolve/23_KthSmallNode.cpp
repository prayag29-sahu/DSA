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

void kthSmallestUtil(Node *root, int &k, int &result)
{
    if (root == nullptr)
        return;

    kthSmallestUtil(root->left, k, result);
    k--;
    if (k == 0)
    {
        result = root->data;
        return;
    }
    kthSmallestUtil(root->right, k, result);
}

int kthSmallest(Node *root, int k)
{
    int result = -1;
    kthSmallestUtil(root, k, result);
    return result;
}

int main()
{
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);

    int k = 3;
    cout << "Kth smallest element is: " << kthSmallest(root, k);
    return 0;
}
