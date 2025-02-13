// C++ program to insert a node in AVL tree
#include <iostream>
#define null 0
using namespace std;

typedef struct AVL
{
    int data;
    AVL *left, *right;
    int height;

    AVL(int k)
    {
        data = k;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
}A;

A *p, *q, *r, *n, *temp, *ttemp;

int height(A *n)
{
    if (n == nullptr)
        return 0;
    return n->height;
}

A *rightRotate(A *p)
{
    q = p->left;
    temp = q->right;

    q->right = p;
    p->left = temp;

    p->height = 1 + max(height(p->left),
                        height(p->right));
    q->height = 1 + max(height(q->left),
                        height(q->right));

    return q;
}

A *leftRotate(A *q)
{
    p = q->right;
    temp = p->left;

    p->left = q;
    q->right = temp;

    
    q->height = 1 + max(height(q->left),
                        height(q->right));
    p->height = 1 + max(height(p->left),
                        height(p->right));

    
    return p;
}

int getBalance(AVL *n)
{
    if (n == nullptr)
        return 0;
    return height(n->left) - height(n->right);
}

AVL *insert(AVL *node, int data)
{

    if (node == nullptr)
        return new AVL(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else 
        return node;

    node->height = 1 + max(height(node->left),
                        height(node->right));

   int balance = getBalance(node);

    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    if (balance > 1 && data > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && data < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}


void preOrder(AVL *root)
{
    if (root != nullptr)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    AVL *root = nullptr;

    root = insert(root, 16);
    root = insert(root, 23);
    root = insert(root, 9);
    root = insert(root, 163);
    root = insert(root, 64);
    root = insert(root, 29);
    root = insert(root, 73);
    root = insert(root, 83);
    root = insert(root, 90);
    root = insert(root, 96);

    cout << "Preorder traversal : \n";
    preOrder(root);

    return 0;
}