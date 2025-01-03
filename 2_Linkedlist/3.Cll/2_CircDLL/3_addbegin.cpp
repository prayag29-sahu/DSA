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

node *first, *temp, *ttemp;

void init()
{
    first = temp = ttemp = null;
}

void createfirst(int val)
{
    first = (node *)malloc(sizeof(node));
    first->data = val;
    first->next = first->prev = first;
}

void addnode(int val)
{
    temp = first;
    while (temp->next != first)
    {
        temp = temp->next;
    }
    ttemp = (node *)malloc(sizeof(node));
    ttemp->data = val;
    ttemp->next = first;
    ttemp->prev = temp;
    temp->next = ttemp;
}

void addbegin(int val)
{
    temp = first;
    while (temp->next != first)
    {
        temp = temp->next;
    }
    ttemp = (node *)malloc(sizeof(node));
    ttemp->data = val;
    ttemp->next = first;
    first->prev = temp;
    temp->prev = first;
    temp->next = ttemp;
    first = ttemp;
}
void display()
{
    temp = first;
    do
    {
        cout << temp->data << endl;
        temp = temp->next;
    } while (temp != first);
}

int main()
{
    int val, n;
    char ans;
l1:
    cout << "1.for enter 1st node\n2.for add new nodes\n3.for add at beginning\n4.display\n"
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
    }
    goto l1;
    return 0;
}