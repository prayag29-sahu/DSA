#include <iostream>
using namespace std;
#define max 5
struct Stack
{
    int data[max];
    int top;
} s;

Stack *p;

void init(Stack *p)
{
    p->top = -1;
}

int Full(Stack *p)
{
    if (p->top == max - 1)
        return 1;
    else
        return 0;
}

int Empty(Stack *p)
{
    if (p->top == -1)
        return 1;
    else
        return 0;
}

void push(Stack *p, int x)
{
    if (Full(p) == 1)
    {
        cout << "Stack is full" << endl;
        return;
    }
    p->top = p->top + 1;
    p->data[p->top] = x;
}

int pop(Stack *p)
{
    int x;
    if (Empty(p) == 1)
    {
        cout << "Stack is Empty" << endl;
        return -1;
    }
    else
    {
        x = p->data[p->top];
        p->top = p->top - 1;
        return x;
    }
}

void display(Stack *p)
{
    for (int i = 0; i <= p->top; i++)
    {
        cout << p->data[i] << endl;
    }
}

int main()
{
    Stack s1, s2;
    int choice, x, a;
    init(&s1);
    init(&s2);
    while (1)
    {
        cout << "Enter an Operation to Perform" << endl;
        cout << "1.Push Operation" << endl;
        cout << "2.Pop Operation" << endl;
        cout << "3.Display 1st Stack" << endl;
        cout << "4.Display 2nd Stack" << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter a value to insert in the stack: ";
            cin >> x;
            push(&s1, x);
        }

        else if (choice == 2)
        {
            a = pop(&s1);
            push(&s2, a);
        }

        else if (choice == 3)
        {
            cout << "Stack 1:- " << endl;
            display(&s1);
        }

        else if (choice == 4)
        {
            cout << "Stack 2:- " << endl;
            display(&s2);
        }

        else
            break;
    }
    return 0;
}