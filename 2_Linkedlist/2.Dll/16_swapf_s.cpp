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

node *first, *temp, *ttemp, *p, *q;

void init()
{
    first = temp = ttemp = null;
}

void createfirst(int val)
{
    first = (node *)malloc(sizeof(node));
    first->data = val;
    first->next = null;
}

void addnode(int val)
{
    temp = first;
    while (temp->next != null)
    {
        temp = temp->next;
    }
    ttemp = (node *)malloc(sizeof(node));
    temp->next = ttemp;
    ttemp->data = val;
    ttemp->next = null;
}

void addbegin(int val)
{
    temp = (node *)malloc(sizeof(node));
    temp->data = val;
    temp->next = first;
    first->prev = temp;
    temp->prev = null;
    first = temp;
}

void addatend(int val)
{
    temp = first;
    ttemp = (node *)malloc(sizeof(node));
    ttemp->data = val;
    ttemp->next = null;

    if (temp == null)
    {
        cout << "list was empty." << endl;
        temp = ttemp;
    }
    else
    {
        while (temp->next != null)
        {
            temp = temp->next;
        }
        temp->next = ttemp;
    }
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
    temp->next = p;
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
    ttemp->next = p;
}

void del(int x)
{
    temp = first;
    while (temp->data != x)
    {
        ttemp = temp;
        temp = temp->next;
    }
    ttemp->next = temp->next;
    free(temp);
}

void delfst()
{
    temp = first;
    if (temp == null)
    {
        cout << "list is empty" << endl;
    }
    else if (temp->next == null)
    {
        first = null;
        cout << "list is empty";
    }
    else
    {
        ttemp = temp;
        temp = temp->next;
        temp->next->prev = null;
        first = temp;
        free(ttemp);
    }
    /*
     temp=first;
     first=first->next;
     first->prev=null;
     temp->next=temp->prev=null;
     free(temp);
     */
}

void delend()
{
    ttemp = first;
    while (ttemp->next != null)
    {
        temp = ttemp;
        ttemp = ttemp->next;
    }
    temp->next = null;
    free(ttemp);
}

void delafter(int x)
{
    temp = first;
    while (temp->data != x)
    {
        temp = temp->next;
        ttemp = temp->next;
    }
    temp->next = ttemp->next;
    ttemp->next->prev = temp;
    ttemp->next = ttemp->prev = null;
    free(ttemp);
}

void delbefore(int x)
{
    ttemp = first;
    while (ttemp->next->data != x)
    {
        temp = ttemp;
        ttemp = ttemp->next;
    }
    temp->next = ttemp->next;
    ttemp->next->prev = temp;
    ttemp->next = ttemp->prev = null;
    free(ttemp);
}

void sum()
{
    int s = 0;
    temp = first;
    while (temp != null)
    {
        s = s + temp->data;
        temp = temp->next;
    }
    cout << "Sum of all nodes :" << s << endl;
}

void count()
{
    int count = 0;
    temp = first;
    while (temp != null)
    {
        temp = temp->next;
        count++;
    }
    cout << "Total number of nodes : " << count << endl;
}

void datafound(int d)
{
    temp = first;
    while (temp != null)
    {
        if (temp->data == d)
        {
            cout << "the node data " << d << "found " << endl;
        }
        break;
        temp = temp->next;
    }
    cout << "not found" << endl;
}


void swapf_l()
{
    temp = first;
    while (temp->next != null)
    {
        ttemp = temp;
        temp = temp->next;
    }
    temp->next = first->next;
    temp->prev = null;
    ttemp->next = first;
    first->prev = ttemp;
    first->next = null;
    first = temp;
}
void swapf_s()
{
    temp = first;
    ttemp = temp->next;
    first->next = ttemp->next;
    first->prev = ttemp;
    ttemp->next = first;
    ttemp->prev = null;
    first = ttemp;
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
    int val, n, x, d;
    char ans;
l1:
    cout << "1.for enter 1st node\n2.for add new nodes\n3.for add at beginning\n4.for add at the end\n5.for add after the node\n6.for add before the node\n7.for delete any node\n8.for delete 1stnode\n9.for delete end node\n10.for delete after the given node\n11.for delete before the given node\n12.for counting node and swap\n13.for found node \n14.swap first and last\n15.swap first and second.\n16.display node and their sum\n"
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
        delfst();
        break;
    case 9:
        delend();
        break;
    case 10:
        cout << "Enter value that after the node delete :" << endl;
        cin >> x;
        delafter(x);
        break;
    case 11:
        cout << "Enter value that before the node delete :" << endl;
        cin >> x;
        delbefore(x);
        break;
    case 12:
        count();
        swapf_l();
        break;
    case 13:
        cout << "enter the node value that find :";
        cin >> d;
        datafound(d);
        break;
    case 14:
        swapf_l();
        display();
        break;
    case 15:
        swapf_s();
        display();
        break;
    case 16:
        cout << "Your linked list is :" << endl;
        display();
        sum();
        break;
    }
    goto l1;
    return 0;
}