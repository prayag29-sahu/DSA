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


int main()
{
    const int MAX_SIZE = 100;
    int heap[MAX_SIZE];
    int size = 0;
    int values[] = {50,40,35,30,12,20,25,5};
    int n = sizeof(values) / sizeof(values[0]);
    for (int i = 0; i < n; i++)
    {
        insert_min_heap(heap, size, values[i]);
        cout << "Inserted " << values[i] << " into the min-heap: ";
        for (int j = 0; j < size; j++)
        {
            cout << heap[j] << " ";
        }
        cout << endl;
    }
    return 0;
}
