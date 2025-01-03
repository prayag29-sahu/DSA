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
    while (temp->next != first)
    {
        temp = temp->next;
    }
    ttemp = (node *)malloc(sizeof(node));
    temp->next = ttemp;
    ttemp->data = val;
    ttemp->next = first;
}

void josofus(int n)
{
    temp = first;
    while (temp->next != temp)
    {
        for (int i = 1; i < n - 1; i++)
        {
            temp = temp->next;
        }
        ttemp = temp->next;
        temp->next = ttemp->next;
        free(ttemp);
        temp = temp->next;
    }
    first = temp;
}

void display()
{
    if (first == null)
        return;
    temp = first;
    int count = 0;
    do
    {
        cout << temp->data << endl;
        temp = temp->next;
        count++;
    } while (temp != first);
    cout << "Count = " << count << endl;
}

int main()
{
    int val;
    char ans;
    init();
    cout << "Enter first node value :" << endl;
    cin >> val;
    createfirst(val);
    while (1)
    {
        cout << "Do you want to add more nodes (y/n)? :" << endl;
        cin >> ans;
        if (ans == 'n' || ans == 'N')
            break;
        cout << "Enter new node value :" << endl;
        cin >> val;
        addnode(val);
    }
    cout << "Your linked list is :" << endl;
    display();
    josofus(3);
    cout << "Remaining node after applying Josephus problem:" << endl;
    display();
}
