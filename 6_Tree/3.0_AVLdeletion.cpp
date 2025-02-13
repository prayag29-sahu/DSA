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
} A;

A *p, *q, *r, *n, *temp, *ttemp;

int height(AVL *n)
{
    if (n == nullptr)
        return 0;
    return n->height;
}

AVL *rightRotate(AVL *p)
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

AVL *leftRotate(AVL *q)
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
AVL *minValueNode(AVL *node)
{
    AVL *current = node;

    while (current->left != nullptr)
        current = current->left;

    return current;
}


AVL *deleteNode(AVL *root, int data)
{

    if (root == nullptr)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);

    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else
    {
        if ((root->left == nullptr) ||
            (root->right == nullptr))
        {
            temp = root->left ? root->left : root->right;

            if (temp == nullptr)
            {
                temp = root;
                root = nullptr;
            }
            else               
                *root = *temp; 
            free(temp);
        }
        else
        {

            temp = minValueNode(root->right);

            root->data = temp->data;

            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == nullptr)
        return root;

    root->height = 1 + max(height(root->left),
                           height(root->right));

    int balance = getBalance(root);

    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 &&
        getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 &&
        getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
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

// Driver Code
int main()
{
    AVL *root = nullptr;

    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);

    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";
    preOrder(root);

    root = deleteNode(root, 10);

    cout << "\nPreorder traversal after"
            " deletion of 10 \n";
    preOrder(root);

    return 0;

    return 0;
}