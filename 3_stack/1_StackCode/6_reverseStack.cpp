#include <stdio.h>
#include <conio.h>
#include <iostream>
#define max 5
using namespace std;
typedef struct stack
{
    int data[max];
    int topA, topB;
} s;
s s1, *p;
void init()
{
    p = &s1;
    p->topA = -1;
    p->topB = max;
}
int EmptyA()
{
    if (p->topA == -1)
        return 1;
    else
        return 0;
}
int EmptyB()
{
    if (p->topB == max)
        return 1;
    else
        return 0;
}
int Full()
{
    if (p->topA + 1 == p->topB)
        return 1;
    else
        return 0;
}
void pushA(int x)
{
    if (Full() == 1)
        return;
    p->topA++;
    p->data[p->topA] = x;
}
void pushB(int x)
{
    if (Full() == 1)
        return;
    p->topB--;
    p->data[p->topB] = x;
}
int popA()
{
    int x;
    if (EmptyA() == 1)
        return 0;
    x = p->data[p->topA];
    p->topA--;
    return x;
}
int popB()
{
    int x;
    if (EmptyB() == 1)
        return 0;
    x = p->data[p->topB];
    p->topB++;
    return x;
}
int reverse()
{
    if (EmptyA() == 1)
        return 0;
    for (int i = 0; i <= p->topA;i++){
        int a = popA();
    for (int i = 0; i <= p->topA; i++)
    {
        int b = popA();
        pushB(b);
    }
    pushA(a);
    for (int i = max-1; i <= p->topB; i--)
    {
        int b = popB();
        pushA(b);
    }
    }
    return 0;
}
void display()
{
    for (int i = 0; i <= p->topA; i++)
    {
        cout << p->data[i] << endl;
    }
    for (int i = max-1; i >= p->topB; i--)
    {
        cout << p->data[i] << endl;
    }
}
int main()
{
    init();
    pushA(10);
    pushA(20);
    pushA(30);
    pushA(40);
    display();
    cout << endl;
    // pushA(50);
    reverse();
    display();

    getch();
}
