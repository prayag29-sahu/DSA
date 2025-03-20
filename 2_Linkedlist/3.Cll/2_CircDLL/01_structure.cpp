#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#define null 0
using namespace std;
struct node
{
    int data;
    struct node *next,*prev;
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
    cout << "enter first node value :";
    cin >> val;
    createfirst(val);
    cout << "your linked list is :";
    display();
}
