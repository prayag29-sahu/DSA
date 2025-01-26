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
    if (p->front == (p->rear+1)%max)
        return 1;
    else
        return 0;
}
void enq(int x)
{
    if (Full() == 1)
        return;
    if (Empty())
        p->front = 0;
    p->rear = (p->rear + 1)%max;
    p->data[p->rear] = x;
}
int deq()
{
    int x;
    if (Empty() == 1)
        return 0;
    x = p->data[p->front];
    p->front = (p->front + 1)%max;
    return x;
}
void display()
{
    int i = p->front;
    while (1)
    {
        cout << p->data[i] << " ";
        if (i == p->rear)
            break;
        i = (i + 1) % max;
    }
}

int main()
{
    init();
    enq(10);
    enq(20);
    enq(30);
    enq(40);
    display();

    cout << endl;
    deq();
    deq();
    display();

}
