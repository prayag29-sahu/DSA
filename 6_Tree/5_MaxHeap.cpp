
#include <iostream>
using namespace std;

#define MAX 1000 

void heapify(int arr[], int n, int i)
{

    int parent = (i - 1) / 2;

    if (arr[parent] > 0)
    {
        if (arr[i] > arr[parent])
        {
            swap(arr[i], arr[parent]);

            heapify(arr, n, parent);
        }
    }
}

void insertNode(int arr[], int &n, int Key)
{

    n = n + 1;

    arr[n - 1] = Key;

    heapify(arr, n, n - 1);
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";

    cout << "\n";
}

int main()
{

    int arr[MAX] = {10, 5, 3, 2, 4};

    int n = 5;

    int key = 15;

    insertNode(arr, n, key);

    printArray(arr, n);

    // 15 5 10 2 4 3 
    return 0;
}