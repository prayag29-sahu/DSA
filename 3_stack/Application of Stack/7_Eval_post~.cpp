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
    char postfix[100];
    init();
    cout << "Enter postfix expression: ";
    gets(postfix);

    int i = 0;
    while (postfix[i] != '\0')
    {
        if (isdigit(postfix[i]))
        {
            int a = postfix[i] - '0'; 
            push(a);
        }
        else
        {
            int op2 = pop();
            int op1 = pop();
            int res;
            switch (postfix[i])
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
        i++;
    }
    cout << "Evaluated result: " << pop() << endl;

    getch();
    return 0;
}
