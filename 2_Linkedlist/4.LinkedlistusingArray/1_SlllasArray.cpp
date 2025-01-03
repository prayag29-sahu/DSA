#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#define max 100
using namespace std;

typedef struct node
{
    int data, next;
} node;

struct node a[max];

int temp = 0;
int head = -1;

void init()
{
    for (int i = 0; i < max - 1; i++)
    {
        a[i].next = i + 1;
    }
    a[max - 1].next = -1;
}

int getnode()
{
    // cout << temp<<endl;
    if (temp == -1)
    {
        cout << "No more node." << endl;
        return -1;
    }
    int p = temp;
    temp = a[temp].next;
    // cout << p<<" "<<temp<<endl;
    return p;
}

void insertAtBeginning(int x)
{
    int q;
    q = getnode();
    // cout << q << endl;
    if (q != -1)
    {
        a[q].data = x;
        a[q].next = head;
        head = q;
    }
}
void insert(int p, int x)
{
    int q;
    q = getnode();
    // cout << q << endl;
    if (q != -1)
    {
        a[q].data = x;
        a[q].next = a[p].next;
        a[p].next = q;
    }
}

void display()
{
    int p = head;
    // cout << p << " " << head;
    while (p != -1)
    {
        cout << a[p].data << " ";
        p = a[p].next;
    }
    cout << endl;
}
void freenode(int p)
{
    a[p].next = temp;
    temp = p;
    return;
}
void deleteNode(int p)
{
    int q;
    // cout << p << " " << head;

    if (p == head)
    {
        q = head;
        head = a[head].next;
        freenode(q);
    }
    else
    {
        int prev = head;
        while (a[prev].next != p)
        {
            prev = a[prev].next;
        }
        q = a[prev].next;
        a[prev].next = a[q].next;
        freenode(q);
    }
}

int main()
{
    init();

    insertAtBeginning(10);
    insertAtBeginning(20);
    insertAtBeginning(30);

    cout << "List after inserting elements at the beginning: ";
    display();

    insert(head, 15);

    cout << "List after inserting 15 after the head: ";
    display();

    deleteNode(head);

    cout << "List after deleting the head: ";
    display();

    return 0;
}
