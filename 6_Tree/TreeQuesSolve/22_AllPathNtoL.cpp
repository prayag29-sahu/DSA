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

void printPaths(Node *root, int path[], int l)
{
    if (root == nullptr)
        return;

    path[l] = root->data;
    l++;

    if (root->left == nullptr && root->right == nullptr)
    {
        for (int i = 0; i < l; i++)
        {
            cout << path[i] << " ";
        }
        cout << endl;
    }
    else
    {
        printPaths(root->left, path, l);
        printPaths(root->right, path, l);
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int path[100]; 
    printPaths(root, path, 0);
    return 0;
}
