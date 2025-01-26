#include <iostream>
using namespace std;

void heapify(int a[], int n, int i)
{
    int large = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] > a[large])
    {
        large = l;
    }

    if (r < n && a[r] > a[large])
    {
        large = r;
    }

    if (large != i)
    {
        int t = a[i];
        a[i] = a[large];
        a[large] = t;

        heapify(a, n, large);
    }
}

void heapSort(int a[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }

    for (int i = n - 1; i > 0; i--)
    {
        int t = a[0];
        a[0] = a[i];
        a[i] = t;
        heapify(a, i, 0);
    }
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int a[] = {9, 4, 3, 8, 10, 2, 5};
    int n = sizeof(a) / sizeof(a[0]);

    heapSort(a, n);

    cout << "Sorted array is \n";
    printArray(a, n);

    return 0;
}
