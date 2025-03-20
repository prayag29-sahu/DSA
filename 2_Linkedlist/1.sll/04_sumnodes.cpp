#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#define null 0
using namespace std;

struct node
{
    int data;
    struct node *next;
};

node *first, *temp, *ttemp;

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
    temp = first;
    if (temp == null)
    {
        cout << "list was empty." << endl;
    }
    else
    {
        ttemp = (node *)malloc(sizeof(node));
        ttemp->data = val;
        ttemp->next = temp;
        first = ttemp;
    }
}

void sum()
{
    int s = 0;
    temp = first;
    while (temp!=null)
    {
        s = s + temp->data;
        temp = temp->next;
    }
    cout << "Sum of all nodes :" << s << endl;
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
    int val, n;
    char ans;
l1:
    cout << "1.for enter 1st node\n2.for add new nodes\n3.for add at beginning\n4.display node and their sum\n"
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
        cout << "Your linked list is :" << endl;
        display();
        sum();
    }
    goto l1;
    return 0;
}
