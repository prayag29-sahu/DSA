#include <stdio.h>
#include <conio.h>
#include <iostream>
#define null 0

using namespace std;

typedef struct stack
{
    int data;
    stack *next;
} s;

s *top, *temp;

void init()
{
    top = null;
}

int Empty()
{
    return top == null;
}

void push(int x)
{
    temp = (stack *)malloc(sizeof(stack));
    if (temp == null)
    {
        cout << "Stack overflow" << endl;
        return;
    }
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop()
{
    if (Empty())
    {
        cout << "Stack underflow" << endl;
        return 0;
    }
    temp = top;
    int x = temp->data;
    top = top->next;
    free(temp);
    return x;
}

void display()
{
    temp = top;
    while (temp != null)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    init();
    push(10);
    push(20);
    push(30);
    push(40);

    cout << "Stack after pushes: ";
    display();

    pop();
    pop();

    cout << "Stack after pops: ";
    display();

    getch();
    return 0;
}
