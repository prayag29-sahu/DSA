#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *first, *last, *ptemp, *temp, *q, *ttemp, *ntemp, *ptr;

void initialization()
{
    first = last = temp = NULL;
}

void FirstNode(int value)
{
    first = (node *)malloc(sizeof(node));
    first->data = value;
    first->next = first;
    last = first;
}

void AddNode(int value)
{
    temp = first;
    while (temp->next != first)
    {
        temp = temp->next;
    }
    ptr = (node *)malloc(sizeof(node));
    ptr->data = value;
    ptr->next = first;
    temp->next = ptr;
    last = ptr;
}

void AfterData(int x, int value)
{
    temp = first;
    while (temp->data != x)
    {
        temp = temp->next;
        ttemp = temp->next;
    }
    ptr = (node *)malloc(sizeof(node));
    ptr->data = value;
    ptr->next = ttemp;
    temp->next = ptr;
}

void BeforeData(int x, int value)
{
    temp = first;
    while (temp->data != x)
    {
        ttemp = temp;
        temp = temp->next;
    }
    ptr = (node *)malloc(sizeof(node));
    ptr->data = value;
    ptr->next = temp;
    ttemp->next = ptr;
}
void swapf_l()
{
    temp = first;
    while (temp->next != first)
    {
        ttemp = temp;
        temp = temp->next;
    }
    ptemp = first->next;
    ttemp->next = first;
    temp->next = ptemp;
    temp->next = first->next;
    first->next = temp;
    first = temp;
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
    int value, choice2, x;
    char choice;
    cout << "Circular Linked List Programs" << endl;
    cout << "Enter the Value of the first node: ";
    cin >> value;
    FirstNode(value);
    cout << "First Node has been Created!" << endl;

    while (1)
    {
        cout << "Do you want to continue?: ";
        cin >> choice;
        if (choice == 'n' || choice == 'N')
            break;
        cout << "Choose an Action to Perform :-" << endl;
        cout << "1.Append" << endl;
        cout << "2.Add Node After the Node Of Given Data" << endl;
        cout << "3.Add Node Before the Node of Given Data" << endl;
        cout << "4.Swap the first and last node" << endl;
        cin >> choice2;
        if (choice2 == 1)
        {
            cout << "Enter Value of the next node: ";
            cin >> value;
            AddNode(value);
        }
        if (choice2 == 2)
        {
            cout << "Enter The Data Of the node after which you want to add a new node: ";
            cin >> x;
            cout << "Enter Value of the new node: ";
            cin >> value;
            AfterData(x, value);
        }
        if (choice2 == 3)
        {
            cout << "Enter The Data Of the node before which you want to add a new node: ";
            cin >> x;
            cout << "Enter Value of the new node: ";
            cin >> value;
            BeforeData(x, value);
        }
        if (choice2 == 4)
        {
            swapf_l();
        }

        if (choice2 == 5)
        {
        }
    }
    cout << "Final Linked List:- " << endl;
        display();
}
