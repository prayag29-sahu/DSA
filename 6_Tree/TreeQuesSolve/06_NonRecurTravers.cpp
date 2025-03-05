#include <iostream>
#include <stack>
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
Node *temp,*root;
void inOrder(Node *root)
{
    stack<Node *> s;
    temp = root;

    while (temp != nullptr || !s.empty())
    {
        while (temp != nullptr)
        {
            s.push(temp);
            temp = temp->left;
        }

        temp = s.top();
        s.pop();

        cout << temp->data << " ";

        temp = temp->right;
    }
}

void preOrder(Node *root)
{
    if (root == nullptr)
        return;

    stack<Node *> s;
    s.push(root);

    while (!s.empty())
    {
        temp = s.top();
        s.pop();

        cout << temp->data << " "; 

        if (temp->right != nullptr)
            s.push(temp->right);
        if (temp->left != nullptr)
            s.push(temp->left);
    }
}

void postOrder(Node *root)
{
    if (root == nullptr)
        return;

    stack<Node *> s1, s2;
    s1.push(root);

    while (!s1.empty())
    {
        temp = s1.top();
        s1.pop();
        s2.push(temp);

        if (temp->left != nullptr)
            s1.push(temp->left);
        if (temp->right != nullptr)
            s1.push(temp->right);
    }

    while (!s2.empty())
    {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

int main()
{
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "In-order Traversal: ";
    inOrder(root);
    cout << endl;

    cout << "Pre-order Traversal: ";
    preOrder(root);
    cout << endl;

    cout << "Post-order Traversal: ";
    postOrder(root);
    cout << endl;

    return 0;
}
