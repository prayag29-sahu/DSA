#include <iostream>
using namespace std;

typedef struct tree
{
    int data;
    tree *left, *right;
} t;

t *root, *temp, *ttemp, *p, *q;

void init()
{
    root = temp = ttemp = nullptr;
}

void node(int val)
{
    root = (t *)malloc(sizeof(t));
    root->data = val;
    root->left = root->right = nullptr;
}

void addnode(int val)
{
    if (root == nullptr)
    {
        node(val);
        return;
    }

    temp = root;
    while (temp != nullptr)
    {
        p = temp;
        if (temp->data > val)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    ttemp = (t *)malloc(sizeof(t));
    ttemp->data = val;
    ttemp->left = ttemp->right = nullptr;
    if (p->data > val)
    {
        p->left = ttemp;
    }
    else
    {
        p->right = ttemp;
    }
}

t *parent(t *root, t *node)
{
    if (root == nullptr || root == node)
    {
        return nullptr;
    }

    if (root->left == node || root->right == node)
    {
        return root;
    }

    t *leftParent = parent(root->left, node);
    if (leftParent != nullptr)
    {
        return leftParent;
    }

    return parent(root->right, node);
}

void deletenode(int val)
{
    temp = root;
    while (temp != nullptr && temp->data != val)
    {
        temp = (temp->data > val) ? temp->left : temp->right;
    }

    if (temp == nullptr)
    {
        cout << "Node not found." << endl;
        return;
    }

    ttemp = parent(root, temp);
    if (temp->left == nullptr && temp->right == nullptr)
    {
        if (ttemp->left == temp)
        {
            ttemp->left = nullptr;
        }
        else
        {
            ttemp->right = nullptr;
        }
        delete temp;
    }
    else if (temp->left != nullptr && temp->right == nullptr)
    {
        if (ttemp->left == temp)
        {
            ttemp->left = temp->left;
        }
        else
        {
            ttemp->right = temp->left;
        }
        delete temp;
    }
    else if (temp->left == nullptr && temp->right != nullptr)
    {
        if (ttemp->left == temp)
        {
            ttemp->left = temp->right;
        }
        else
        {
            ttemp->right = temp->right;
        }
        delete temp;
    }
    else
    {
        p = temp->right;
        q = temp;
        while (p->left != nullptr)
        {
            q = p;
            p = p->left;
        }
        temp->data = p->data;
        if (q->left == p)
        {
            q->left = p->right;
        }
        else
        {
            q->right = p->right;
        }
        delete p;
    }
}

void inorder(t *p)
{
    if (p != nullptr)
    {
        inorder(p->left);
        cout << p->data << " ";
        inorder(p->right);
    }
}

void preorder(tree *p)
{
    if (p != nullptr)
    {
        cout << p->data << " ";
        preorder(p->left);
        preorder(p->right);
    }
}

void postorder(tree *p)
{
    if (p != nullptr)
    {
        postorder(p->left);
        postorder(p->right);
        cout << p->data << " ";
    }
}

int main()
{
    init();
    addnode(30);
    addnode(20);
    addnode(50);
    addnode(10);
    addnode(40);
    addnode(60);
    cout << "Inorder traversal of the BST before deletion: ";
    inorder(root);
    cout << endl;
    deletenode(50);
    cout << "Inorder/Preorde/Postorder traversal of the BST after deletion: ";
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    return 0;
}
