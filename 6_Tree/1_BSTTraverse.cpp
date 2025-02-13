#include <iostream>
#define null 0
using namespace std;

typedef struct tree
{
    int data;
    tree *left, *right;
}t;

t *root, *temp, *ttemp, *p;

void init()
{
    root = temp = ttemp = null;
}

void node(int val)
{
    root = (t*)malloc(sizeof(t));
    root->data = val;
    root->left = root->right = null;
}

void addnode(int val)
{
    temp = root;
    while (temp != null)
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
    ttemp->left = ttemp->right = null;
    if (p->data > val)
    {
        p->left = ttemp;
    }
    else
    {
        p->right = ttemp;
    }
}

void inorder(t *p)
{
    if (p != null)
    {
        inorder(p->left);
        cout << p->data << " ";
        inorder(p->right);
    }
}

void preorder(t *p)
{
    if (p != null)
    {
        cout << p->data << " ";
        preorder(p->left);
        preorder(p->right);
    }
}
void postorder(t *p)
{
    if (p != null)
    {
        postorder(p->left);
        postorder(p->right);
        cout << p->data << " ";
    }
}

int main()
{
    init();
    int val;
    char c;
    cout << "Enter the value for the root node: ";
    cin >> val;
    node(val);
    while (true)
    {
        cout << "Add new node (y/n): ";
        cin >> c;
        if (c == 'y')
        {
            cout << "Enter the node value: ";
            cin >> val;
            addnode(val);
        }
        else
        {
            break;
        }
    }
    cout << "Inorder traversal of the BST: ";
    inorder(root);
    cout << endl;
    cout << "Preorder traversal of the BST: ";
    preorder(root);
    cout << endl;
    cout << "Preorder traversal of the BST: ";
    postorder(root);
}
