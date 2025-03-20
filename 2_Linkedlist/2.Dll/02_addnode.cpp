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
    int val;
    char ans;
    cout << "Enter first node value :" << endl;
    cin >> val;
    createfirst(val);
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
    cout << "Your linked list is :" << endl;
    display();
}
