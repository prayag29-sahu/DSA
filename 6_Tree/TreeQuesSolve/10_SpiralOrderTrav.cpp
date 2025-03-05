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
Node *root, *temp;
void spiralOrderTraversal(Node *root)
{
    if (root == nullptr)
        return;

    Node *SLToR[100]; // odd levels stack (left to right)
    Node *SRToL[100]; // even levels stack (right to left)

    int topLToR = -1; 
    int topRToL = -1;
    topLToR++;
    SLToR[topLToR] = root;

    while (topLToR >= 0 || topRToL>= 0)
    {
        while (topLToR >= 0)
        {
            temp = SLToR[topLToR];
            topLToR--;
            cout << temp->data << " ";                     

            if (temp->left)
                SRToL[++topRToL] = temp->left;
            if (temp->right)
                SRToL[++topRToL] = temp->right;
        }

        while (topRToL >= 0)
        {
            temp = SRToL[topRToL--]; 
            cout << temp->data << " ";                     

            if (temp->right)
                SLToR[++topLToR] = temp->right;
            if (temp->left)
                SLToR[++topLToR] = temp->left;
        }
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
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);

    cout << "Spiral Order Traversal: ";
    spiralOrderTraversal(root);
    cout << endl;

    return 0;
}
