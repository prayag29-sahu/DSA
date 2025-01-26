#include <iostream>
#define null 0

using namespace std;

typedef struct lqueue
{
    int data;
    lqueue *next;
} q;

q *front, *rear, *temp;

void init()
{
    front = rear = null;
}

void enq(int x)
{
    temp = (lqueue *)malloc(sizeof(lqueue));
    if (temp == null)
    {
        return;
    }
    temp->data = x;
    temp->next = null;
    if (rear == null)
    {
        rear = front = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

int deq()
{
    int x;
    if (front == null)
    {
        return 0;
    }
    temp = front;
    if (front == rear)
    {
        front = rear = null;
    }
    else
        front = front->next;
    x = temp->data;
    free(temp);
    return x;
}

void display()
{
    temp = front;
    while (temp != null)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    init();
    enq(10);
    enq(20);
    enq(30);
    enq(40);

    cout << "Queue after Insertion: ";
    display();

    deq();
    deq();

    cout << "Queue after Deletion: ";
    display();

    return 0;
}
