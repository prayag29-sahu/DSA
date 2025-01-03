#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <iostream>
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

int priority(char x)
{
   if (x == '(')
      return (0);
   if (x == '+' || x == '-')
      return (1);
   if (x == '*' || x == '/')
      return (2);
   if (x == '^')
      return (3);

   return 0;
}

int empty()
{
   if (p->top == -1)
      return (1);
   else
      return (0);
}

int full()
{
   if (p->top == MAX - 1)
      return (1);
   else
      return (0);
}

void push(char x)
{
   p->top = p->top + 1;
   p->data[p->top] = x;
}

char pop()
{
   int x;
   x = p->data[p->top];
   p->top = p->top - 1;
   return (x);
}
char top()
{
   return (p->data[p->top]);
}
int main()
{

   char x;
   char infix[100];
   int i = 0;
   init();
   cout << "Enter infix expression:";
   gets(infix);
   while (infix[i] != '\0')
   {
      if (isalnum(infix[i]))
         cout << infix[i];
      else if (infix[i] == '(')
         push('(');
      else
      {
         if (infix[i] == ')')
            while ((x = pop()) != '(')
               cout << x;
         else
         {
            while (priority(infix[i]) <= priority(top()) && !empty())
            {
               x = pop();
               cout << x;
            }
            push(infix[i]);
         }
      }
      i++;
   }
   while (!empty())
   {
      x = pop();
      cout << x;
   }
   getch();
}
