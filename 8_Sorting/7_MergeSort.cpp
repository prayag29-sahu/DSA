#include <iostream>
using namespace std;

void marge(int a[], int l, int mid, int h)
{
    int i = l, j = mid + 1, temp[5], k = l, s = 0;
    while (i <= mid && j <= h)
    {
        if (a[i] < a[j])
        {
            temp[k] = a[i];
            i++;
        }
        else
        {
            temp[k] = a[j];
            j++;
        }
        k++;
    }
    if (j > h)
    {
        for (; i <= mid; i++)
        {
            temp[k] = a[i];
            k++;
        }
    }
    if(i>mid)
    {
        for (; j <= h;j++)
        {
            temp[k] = a[j];
            k++;
        }
    }
    for (s = l; s <= h;s++)
    {
        a[s] = temp[s];
    }
}

void marge_sort(int a[],int l,int h)
{
    int mid = 0;
    if(l<h)
    {
        mid=(l+h)/2;
        marge_sort(a, l, mid);
        marge_sort(a, mid + 1, h);
        marge(a, l, mid, h);
    }
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

    marge_sort(a, 0,5);
    cout << endl;
    for (int i = 0; i <= n - 1; i++)
    {
        cout << a[i] << " ";
    }
}