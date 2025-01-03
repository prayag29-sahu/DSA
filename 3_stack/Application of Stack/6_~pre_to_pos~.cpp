#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <iostream>
#include <cstring>
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
    string str1, str2, str3;
    char prefix[100];
    int i;

    init();
    cout << "Enter prefix expression: ";
    gets(prefix);

    int len = strlen(prefix);

    for (i = len - 1; i >= 0; i--)
    {
        if (isalnum(prefix[i]))
        {
            string a(1, prefix[i]);
            push(a);
        }
        else
        {
            str1 = pop();
            str2 = pop();
            str3 = str1 + str2 + prefix[i];
            // str3 = "(" + str1 + prefix[i] + str2 + ")";
            push(str3);
        }
    }

    cout << "Infix expression: " << top() << endl;

    getch();
    return 0;
}
//-ab s1=- s2=a s3=b ab-  s4=s2+s3+s1