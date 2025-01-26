#include <iostream>
#define max 5
using namespace std;

typedef struct
{
    int data[max];
    int priority[max];
    int front, rear;
} pq;
pq q, *p;

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
    if (p->rear == max - 1)
        return 1;
    else
        return 0;
}

void enqueue(int x, int prio)
{
    if (Full()==1)
    {
        return;
    }
    if (p->front == -1)
    {
        p->front = 0;
    }
    p->rear++;
    p->data[p->rear] = x;
    p->priority[p->rear] = prio;

    for (int i = p->rear; i > p->front; --i)
    {
        if (p->priority[i] < p->priority[i - 1])
        {

            int temp = p->priority[i];
            p->priority[i] = p->priority[i - 1];
            p->priority[i - 1] = temp;

            int tempData = p->data[i];
            p->data[i] = p->data[i - 1];
            p->data[i - 1] = tempData;
        }
        else
        {
            break;
        }
    }
}

int dequeue()
{
    if (Empty())
    {
        return -1;
    }
    int x = p->data[p->front];
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

void display()
{
    for (int i = p->front; i <= p->rear; i++)
    {
        cout << p->data[i] << " ";
        cout << p->priority[i] << " "<<endl;
    }
}

int main()
{
    init();
    enqueue(10, 2);
    enqueue(20, 1);
    enqueue(30, 3);
    enqueue(40, 0);
    display();
    cout << endl;
    dequeue();
    display();
}
