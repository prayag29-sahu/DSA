#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <iostream>
#include <string>
#define MAX 100
using namespace std;

typedef struct stack
{
    string data[MAX];
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

void push(string x)
{
    if (Full())
        return;
    p->top = p->top + 1;
    p->data[p->top] = x;
}

string pop()
{
    if (Empty())
        return "";
    string x = p->data[p->top];
    p->top = p->top - 1;
    return x;
}

string top()
{
    if (Empty())
        return "";
    return p->data[p->top];
}

int main()
{
    string str1, str2, str3, str4, str5;
    char postfix[100];
    int i = 0;
    init();
    cout << "Enter postfix expression: ";
    gets(postfix);

    while (postfix[i] != '\0')
    {
        if (isalnum(postfix[i]))
        {
            string a(1, postfix[i]);
            // cout << postfix[i] << endl;
            push(a);
        }
        else
        {
            str1 = pop();
            str2 = pop();
            str3 =  str2 + postfix[i] + str1 ;
            // str3 = "(" + str2 + postfix[i] + str1 + ")";
            push(str3);
        }
        i++;
    }

    cout << "Infix expression: " << top() << endl;

    getch();
    return 0;
}
