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

Node *findNodeAndParent(Node *root, int data, Node *&parent)
{
    if (root == nullptr)
        return nullptr;

    if (root->left && root->left->data == data)
    {
        parent = root;
        return root->left;
    }
    if (root->right && root->right->data == data)
    {
        parent = root;
        return root->right;
    }

    Node *leftSearch = findNodeAndParent(root->left, data, parent);
    if (leftSearch != nullptr)
        return leftSearch;

    return findNodeAndParent(root->right, data, parent);
}
void swapNodes(Node *root, int data1, int data2)
{
    if (root == nullptr)
        return;

    Node *parent1 = nullptr;
    Node *parent2 = nullptr;

    Node *node1 = findNodeAndParent(root, data1, parent1);
    Node *node2 = findNodeAndParent(root, data2, parent2);

    if (node1 == nullptr || node2 == nullptr)
    {
        cout << "Either one or both nodes not found in the tree." << endl;
        return;
    }
    // cout << parent1->left->data << endl;
    // cout << parent1->right->data << endl;
    // cout << parent2->left->data << endl;
    // cout << parent2->right->data << endl;

    if (parent1 != nullptr)
    {
        if (parent1->left == node1)
            parent1->left = node2;
        else
            parent1->right = node2;
    }
    else
    {
        root = node2;
    }

    if (parent2 != nullptr)
    {
        if (parent2->left == node2)
            parent2->left = node1;
        else
            parent2->right = node1;
    }
    else
    {
        root = node1;
    }
    // cout << parent1->data << endl;
    // cout << parent1->data << endl;
    // cout << parent2->data << endl;
    // cout << parent2->data << endl;
    Node *tempLeft = node1->left;
    Node *tempRight = node1->right;

    node1->left = node2->left;
    node1->right = node2->right;

    node2->left = tempLeft;
    node2->right = tempRight;
}

void inOrder(Node *node)
{
    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "In-order Traversal of Original Tree: ";
    inOrder(root);
    cout << endl;

    swapNodes(root, 4, 6);
    cout << "In-order Traversal after swapping : ";
    inOrder(root);
    cout << endl;

    return 0;
}
