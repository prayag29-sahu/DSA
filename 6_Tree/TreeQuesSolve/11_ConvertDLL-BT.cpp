#include <iostream>
using namespace std;

typedef struct ListNode
{
    int data;
    ListNode *prev;
    ListNode *next;

    ListNode(int val)
    {
        data = val;
        prev = next = nullptr;
    }
}LN;
LN *slow, *fast, *mid, *head;
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
TreeNode *root;

ListNode *findMiddle(ListNode *start, ListNode *end)
{
    if (start == nullptr)
        return nullptr;

        slow = start;
        fast = start;

    while (fast != end && fast->next != end)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

TreeNode *DLLToBT(ListNode *start, ListNode *end)
{
    if (start == end)
        return nullptr;

    mid = findMiddle(start, end);

    root = new TreeNode(mid->data);

    root->left = DLLToBT(start, mid);
    root->right = DLLToBT(mid->next, end);

    return root;
}

void inOrder(TreeNode *root)
{
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->prev = head;
    head->next->next = new ListNode(3);
    head->next->next->prev = head->next;
    head->next->next->next = new ListNode(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->prev = head->next->next->next->next;
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->prev = head->next->next->next->next->next;

    cout << "Doubly Linked List: ";
    printList(head);

    root = DLLToBT(head, nullptr);

    cout << "In-order Traversal of the Binary Tree: ";
    inOrder(root);
    cout << endl;

    return 0;
}
