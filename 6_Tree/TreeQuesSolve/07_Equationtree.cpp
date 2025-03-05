#include <iostream>
using namespace std;

struct Node
{
    char data; 
    Node *left;
    Node *right;

    Node(char val)
    {
        data = val;
        left = right = nullptr;
    }
};

Node *root,*n5, *n3, *n4, *n2, *n6, *n9, *expNode, *mulNode, *divNode, *addNode, *subNode;

Node *ExpressionTree()
{
    // 5 + 3 * 4 - 2 ^ 6 / 9
    n5 = new Node('5');
    n3 = new Node('3');
    n4 = new Node('4');
    n2 = new Node('2');
    n6 = new Node('6');
    n9 = new Node('9');

    expNode = new Node('^');
    expNode->left = n2;
    expNode->right = n6;

    mulNode = new Node('*');
    mulNode->left = n3;
    mulNode->right = n4;

    divNode = new Node('/');
    divNode->left = expNode; // 2 ^ 6
    divNode->right = n9;

    addNode = new Node('+');
    addNode->left = n5;
    addNode->right = mulNode; // 3 * 4

    subNode = new Node('-');
    subNode->left = addNode;  // 5 + 3 * 4
    subNode->right = divNode; // (2 ^ 6) / 9

    return subNode;
}

void inOrder(Node *node)
{
    inOrder(node->left);

    cout << node->data << " ";

    inOrder(node->right);
}

void preOrder(Node *node)
{
    cout << node->data << " ";

    preOrder(node->left);

    preOrder(node->right);
}

void postOrder(Node *node)
{
    postOrder(node->left);

    postOrder(node->right);

    cout << node->data << " ";
}

int main()
{
    root = ExpressionTree();

    cout << "In-order Traversal : ";
    inOrder(root);
    cout << endl;

    cout << "Pre-order Traversal : ";
    preOrder(root);
    cout << endl;

    cout << "Post-order Traversal : ";
    postOrder(root);
    cout << endl;

    return 0;
}
