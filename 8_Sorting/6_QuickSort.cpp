#include <iostream>
using namespace std;

void quick_sort(int a[], int lb, int ub)
{
    int x, l, r, t;
    if (lb >= ub)
    {
        return;
    }
    l = lb;
    r = ub;
    x = a[lb];
    while (l < r)
    {
        while (a[l] <= x && l < r)
            l++;
        while (a[r] > x)
            r--;
        if (l < r)
        {
            t = a[l];
            a[l] = a[r];
            a[r] = t;
        }
    }
    a[lb] = a[r];
    a[r] = x;
    quick_sort(a, lb, r - 1);
    quick_sort(a, r + 1, ub);
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i <= n - 1; i++)
    {
        cin >> a[i];
    }

    quick_sort(a, 0, 4);
    cout << endl;
    for (int i = 0; i <= n - 1; i++)
    {
        cout << a[i] << " ";
    }
}