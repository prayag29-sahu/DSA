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
    first->next = first;
}

void addnode(int val)
{
    temp = first;
    while(temp->next!=first)
    {
        temp = temp->next;
    }
    ttemp = (node *)malloc(sizeof(node));
    temp->next = ttemp;
    ttemp->data = val;
    ttemp->next = first;
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
    int val;
    char ans;
    cout << "Enter first node value :" << endl;
    cin >> val;
    createfirst(val);
    while (1)
    {
        cout << "Enter Do u Want to continue :" << endl;
        cin >> ans;
        if(ans == 'n' || ans == 'N')
            break;
        cout << "Enter new node value :" << endl;
        cin >> val;
        addnode(val);
    }
        cout << "Your linked list is :" << endl;
    display();
}