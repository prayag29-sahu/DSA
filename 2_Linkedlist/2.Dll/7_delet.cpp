#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#define null 0
using namespace std;
struct node
{
    int data;
    struct node *next, *prev;
};

node *first, *temp, *ttemp, *p;

void init()
{
    first = temp = ttemp = null;
}

void createfirst(int val)
{
    first = (node *)malloc(sizeof(node));
    first->data = val;
    first->next = first->prev = null;
}

void addnode(int val)
{
    temp = first;
    while (temp->next != null)
    {
        temp = temp->next;
    }
    ttemp = (node *)malloc(sizeof(node));
    ttemp->data = val;
    ttemp->next = null;
    ttemp->prev = temp;
    temp->next = ttemp;
}

void addbegin(int val)
{
    temp = first;
    ttemp = (node *)malloc(sizeof(node));
    ttemp->data = val;
    ttemp->next = temp;
    ttemp->prev = null;
    first = ttemp;
}

void addatend(int val)
{
    temp = first;
    while (temp->next != null)
    {
        temp = temp->next;
    }
    ttemp = (node *)malloc(sizeof(node));
    ttemp->data = val;
    ttemp->next = null;
    ttemp->prev = temp;
    temp->next = ttemp;
}

void addafter(int x, int val)
{
    temp = first;
    while (temp->data != x)
    {
        temp = temp->next;
    }
    ttemp = temp->next;
    p = (node *)malloc(sizeof(node));
    p->data = val;
    p->next = ttemp;
    p->prev = temp;
    temp->next = p;
    ttemp->prev = p;
}

void addbefore(int x, int val)
{
    temp = first;
    while (temp->data != x)
    {
        ttemp = temp;
        temp = temp->next;
    }
    p = (node *)malloc(sizeof(node));
    p->data = val;
    p->next = temp;
    p->prev = ttemp;
    ttemp->next = p;
    temp->prev = p;
}

void del(int x)
{
    temp = first;
    while(temp->data!=x)
    {
        ttemp = temp;
        temp = temp->next;
    }
    ttemp->next = temp->next;
    free(temp);
}

void display()
{
    temp = first;
    while (temp != null)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int main()
{
    int val, n, x;
    char ans;
l1:
    cout << "1.for enter 1st node\n2.for add new nodes\n3.for add at beginning\n4.for add at the end\n5.for add after the node\n6.for add before the node\n7.for delet any node\n8.display node\n"
         << endl;
    cin >> n;
    switch (n)
    {
    case 1:
        cout << "Enter first node value :" << endl;
        cin >> val;
        createfirst(val);
        break;
    case 2:
        while (1)
        {
            cout << "Enter Do u Want to continue :" << endl;
            cin >> ans;
            if (ans == 'n' || ans == 'N')
                break;
            cout << "Enter new node value :" << endl;
            cin >> val;
            addnode(val);
        }
        break;
    case 3:
        cout << "Enter node value add at beginning :" << endl;
        cin >> val;
        addbegin(val);
        break;
    case 4:
        cout << "Enter node value add at end :" << endl;
        cin >> val;
        addatend(val);
        break;
    case 5:
        cout << "Enter node value add after the new node :";
        cin >> x;
        cout << "Enter new node value :";
        cin >> val;
        addafter(x, val);
        break;
    case 6:
        cout << "Enter node value add before the new node :";
        cin >> x;
        cout << "Enter new node value :";
        cin >> val;
        addbefore(x, val);
        break;
    case 7:
        cout << "Enter node value for delete :" << endl;
        cin >> x;
        del(x);
        break;
    case 8:
        cout << "Your linked list is :" << endl;
        display();
        break;
    }
    goto l1;
    return 0;
}