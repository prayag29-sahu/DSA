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

node  *temp, *ttemp;

void init(node *&p)
{
    p = null;
}

void createfirst(node *&p, int val)
{
    p = (node *)malloc(sizeof(node));
    p->data = val;
    p->next = p;
}

void addnode(node *&p, int val)
{
    temp = p;
    while (temp->next != p)
    {
        temp = temp->next;
    }
    ttemp = (node *)malloc(sizeof(node));
    temp->next = ttemp;
    ttemp->data = val;
    ttemp->next = p;
}

void concat(node *&l1, node *l2)
{
    if (l1 == null)
    {
        l1 = l2;
        return;
    }
    temp = l1;
    while (temp->next != l1)
    {
        temp = temp->next;
    }
    temp->next = l2;
    temp = l2;
    while (temp->next != l2)
    {
        temp = temp->next;
    }
    temp->next = l1;
}

void display(node *p)
{
    temp = p;
    if (p != null)
    {
        do
        {
            cout << temp->data << endl;
            temp = temp->next;
        } while (temp != p);
    }
}

int main()
{
    int val, l;
    node *l1 = null;
    node *l2 = null;
    char ans;
l1:
    cout << "Enter the list (1 or 2): " << endl;
    cin >> l;
    if (l == 1)
    {
        init(l1);
        cout << "Enter first node value: " << endl;
        cin >> val;
        createfirst(l1, val);
        while (1)
        {
            cout << "Do you want to continue (y/n): " << endl;
            cin >> ans;
            if (ans == 'n' || ans == 'N')
                break;
            cout << "Enter new node value: " << endl;
            cin >> val;
            addnode(l1, val);
        }
        cout << "Your linked list is: " << endl;
        display(l1);
        goto l1;
    }
    else
    {
        init(l2);
        cout << "Enter first node value: " << endl;
        cin >> val;
        createfirst(l2, val);
        while (1)
        {
            cout << "Do you want to continue (y/n): " << endl;
            cin >> ans;
            if (ans == 'n' || ans == 'N')
                break;
            cout << "Enter new node value: " << endl;
            cin >> val;
            addnode(l2, val);
        }
        cout << "Your linked list is: " << endl;
        display(l2);
        cout << "Do you want to concatenate (y/n): " << endl;
        cin >> ans;
        if (ans == 'y' || ans == 'Y')
        {
            goto l2;
        }
        goto l1;
    l2:
        concat(l1, l2);
        cout << "Concatenated linked list is: " << endl;
        display(l1);
    }
    return 0;
}
