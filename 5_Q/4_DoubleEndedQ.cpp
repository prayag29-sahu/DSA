#include <iostream>
#define max 5
using namespace std;
typedef struct
{
    int data[max];
    int front, rear;
} aq;
aq q, *p;
void init()
{
    p = &q;
    p->front = -1;
    p->rear = -1;
}
int Empty()
{
    if (p->front == -1)
        return 1;
    else
        return 0;
}
int Full()
{
    if (p->front == 0 && p->rear == max - 1)
        return 1;
    else
        return 0;
}
void benq(int x)
{
    if (Full() == 1)
        return;
    if (p->front == -1)
    {
        p->front = p->rear = 0;
        p->data[p->front] = x;
    }
    else if (p->front != 0)
    {
        --p->front;
        p->data[p->front] = x;
    }
    else
    {
        for (int i = p->rear; i >= p->front; i--)
        {
            p->data[i + 1] = p->data[i];
        }
        p->data[p->front] = x;
        p->rear++;
    }
}
void Eenq(int x)
{
    if (Full() == 1)
        return;
    if (p->rear == -1)
    {
        p->front = p->rear = 0;
        p->data[p->rear] = x;
    }
    else if (p->rear != max - 1)
    {
        ++p->rear;
        p->data[p->rear] = x;
    }
    else
    {
        for (int i = p->front; i <= p->rear; i++)
        {
            p->data[i - 1] = p->data[i];
        }
        p->data[p->rear] = x;
        p->front--;
    }
}
int bdeq()
{
    int x;
    if (Empty() == 1)
        return -1;
    x = p->data[p->front];
    if (p->front == p->rear)
    {
        p->front = p->rear = -1;
    }
    else
    {
        p->front++;
    }
    return x;
}
int Edeq()
{
    int x;
    if (Empty() == 1)
        return -1;
    x = p->data[p->rear];
    if (p->front == p->rear)
    {
        p->front = p->rear = -1;
    }
    else
    {
        p->rear--;
    }
    return x;
}
void display()
{
    for (int i = p->front; i <= p->rear; i++)
    {
        cout << p->data[i] << " ";
    }
}

int main()
{
    init();
    benq(10);
    Eenq(20);
    benq(30);
    Eenq(40);
    display();
    cout << endl;
    bdeq();
    Edeq();
    display();
}
