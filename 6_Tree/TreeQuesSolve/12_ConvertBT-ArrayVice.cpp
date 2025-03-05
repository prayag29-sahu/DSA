#include <iostream>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

int countNodes(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void treeToArray(TreeNode *root, int arr[], int &i)
{
    if (root == nullptr)
        return;

    treeToArray(root->left, arr, i);

    arr[i++] = root->data;

    treeToArray(root->right, arr, i);
}

TreeNode *arrayToTree(int arr[], int start, int end)
{
    if (start > end)
        return nullptr;

    int mid = (start + end) / 2;
    TreeNode *root = new TreeNode(arr[mid]);

    root->left = arrayToTree(arr, start, mid - 1);
    root->right = arrayToTree(arr, mid + 1, end);

    return root;
}

void inOrder(TreeNode *root)
{

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(18);

    int n = countNodes(root);

    int *arr = new int[n];
    int i = 0;

    treeToArray(root, arr, i);

    cout << "Binary Tree as Array (In-order): ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    TreeNode *newRoot = arrayToTree(arr, 0, n - 1);

    cout << "Reconstructed Binary Tree (In-order Traversal): ";
    inOrder(newRoot);
    cout << endl;

    delete[] arr;

    return 0;
}
