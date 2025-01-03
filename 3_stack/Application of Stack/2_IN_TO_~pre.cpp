#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <cstring>
#include <string>
#define max 100
using namespace std;

typedef struct stack
{
    string data[max];
    int topA, topB;
} s;

s s1, *p;

void init()
{
    p = &s1;
    p->topA = -1;
    p->topB = max;
}

int priority(string x)
{
    if (x == "(")
        return 0;
    if (x == "+" || x == "-")
        return 1;
    if (x == "*" || x == "/")
        return 2;
    if (x == "^")
        return 3;
    return 0;
}

int EmptyA()
{
    return p->topA == -1;
}

int EmptyB()
{
    return p->topB == max;
}

int Full()
{
    return p->topA + 1 == p->topB;
}

void pushA(string x)
{
    if (Full())
        return;
    p->topA++;
    p->data[p->topA] = x;
}

void pushB(string x)
{
    if (Full())
        return;
    p->topB--;
    p->data[p->topB] = x;
}

string popA()
{
    if (EmptyA())
        return "";
    string x = p->data[p->topA];
    p->topA--;
    return x;
}

string popB()
{
    if (EmptyB())
        return "";
    string x = p->data[p->topB];
    p->topB++;
    return x;
}

string topA()
{
    if (EmptyA())
        return "";
    return p->data[p->topA];
}

string topB()
{
    if (EmptyB())
        return "";
    return p->data[p->topB];
}

int main()
{
    string str1, str2, str3, str4, str5;
    char infix[100];
    int i = 0;
    init();
    cout << "Enter infix expression: ";
    gets(infix);

    while (infix[i] != '\0')
    {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z') || (infix[i] >= '0' && infix[i] <= '9'))
        {
            string a(1, infix[i]);
            pushB(a);
        }
        // else if (isalnum(infix[i]))
        // {
        //     string a(1, infix[i]);
        //     cout << a << endl;
        //     pushA(a);
        // }
        else if (infix[i] == '(')
        {
            string a(1, '(');
            pushA(a);
        }
        else
        {
            if (infix[i] == ')')
            {
                while ((str1 = popA()) != "(")
                {
                    str2 = popB();
                    str3 = popB();
                    str4 = str3 + str2;
                    str5 = str1 + str4;
                    pushB(str5);
                }
            }
            else
            {
                while (!EmptyA() && priority(string(1, infix[i])) <= priority(topA()))
                {
                    str1 = popA();
                    str2 = popB();
                    str3 = popB();
                    str4 = str3 + str2;
                    str5 = str1 + str4;
                    pushB(str5);
                }
                pushA(string(1, infix[i]));
            }
        }
        i++;
    }

    while (!EmptyA())
    {
        str1 = popA();
        str2 = popB();
        str3 = popB();
        str4 = str3 + str2;
        str5 = str1 + str4;
        pushB(str5);
    }

    cout << "Prefix expression: " << topB() << endl;

    getch();
    return 0;
}
