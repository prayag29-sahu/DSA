#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <iostream>
#include <cstring>
#define MAX 100
using namespace std;

typedef struct stack
{
    int data[MAX];
    int top;
} ss;
ss *p, s;

void init()
{
    p = &s;
    p->top = -1;
}

int Empty()
{
    return p->top == -1;
}

int Full()
{
    return p->top == MAX - 1;
}

void push(int x)
{
    if (Full())
        return;
    p->top = p->top + 1;
    p->data[p->top] = x;
}

int pop()
{
    if (Empty())
        return 0;
    int x = p->data[p->top];
    p->top = p->top - 1;
    return x;
}

int main()
{
    char prefix[100];
    init();
    cout << "Enter prefix expression: ";
    gets(prefix);
    int len = strlen(prefix);

    for (int i = len - 1; i >= 0; i--)
    {
        if (isdigit(prefix[i]))
        {
            int a = prefix[i] - '0'; 
            push(a);
        }
        else
        {
            int op1 = pop();
            int op2 = pop();
            int res;
            switch (prefix[i])
            {
            case '+':
                res = op1 + op2;
                break;
            case '-':
                res = op1 - op2;
                break;
            case '*':
                res = op1 * op2;
                break;
            case '/':
                res = op1 / op2;
                break;
            }
            push(res);
        }
    }
    cout << "Evaluated result: " << pop() << endl;

    getch();
    return 0;
}
