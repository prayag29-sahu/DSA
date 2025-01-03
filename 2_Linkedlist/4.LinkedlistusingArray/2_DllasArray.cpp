#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#define max 100
using namespace std;

typedef struct node
{
    int data, next, prev;
} node;

struct node a[max];

int ttemp = -1;
int temp = 0;
int head = -1;

void init()
{
    for (int i = 0; i < max - 1; i++)
    {
        a[i].next = i + 1;
        a[i].prev = i - 1;
    }
    a[max - 1].next = -1;
    a[max - 1].prev = max - 2;
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
    ttemp = a[temp].prev;
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
        a[q].prev = ttemp;
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
        a[q].prev = a[p].prev;
        a[p].prev = ttemp;
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
    a[p].prev = ttemp;
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
        int pre = head;
        while (a[pre].next != p)
        {
            pre = a[pre].next;

        }
        q = a[pre].next;
        a[pre].next = a[q].next;
        a[pre].prev = a[q].prev;
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
