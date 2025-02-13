#include <iostream>

using namespace std;

void insert_min_heap(int heap[], int &size, int value)
{

    heap[size] = value;
    size++;

    int index = size - 1;

    while (index > 0 && heap[(index - 1) / 2] > heap[index])
    {
        swap(heap[index], heap[(index - 1) / 2]);
       
        index = (index - 1) / 2;
    }
}

void delete_min_heap(int heap[], int &size, int value)
{

    int index = -1;
    for (int i = 0; i < size; i++)
    {
        if (heap[i] == value)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        return;
    }

    heap[index] = heap[size - 1];

    size--;
    while (true)
    {
        int left_child = 2 * index + 1;
        int right_child = 2 * index + 2;
        int smallest = index;
        if (left_child < size && heap[left_child] < heap[smallest])
        {
            smallest = left_child;
        }
        if (right_child < size && heap[right_child] < heap[smallest])
        {
            smallest = right_child;
        }
        if (smallest != index)
        {
            swap(heap[index], heap[smallest]);
            index = smallest;
        }
        else
        {
            break;
        }
    }
}

int main()
{
    const int MAX_SIZE = 100; 
    int heap[MAX_SIZE];
    int size = 0;
    int values[] = {13, 16, 31, 41, 51, 100};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++)
    {
        insert_min_heap(heap, size, values[i]);
    }

    cout << "Initial heap: ";
    for (int j = 0; j < size; j++)
    {
        cout << heap[j] << " ";
    }
    cout << endl;

    delete_min_heap(heap, size, 13);
    cout << "Heap after deleting 13: ";
    for (int j = 0; j < size; j++)
    {
        cout << heap[j] << " ";
    }
    cout << endl;

    return 0;
}
