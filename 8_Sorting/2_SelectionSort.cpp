#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i <= n - 1; i++)
    {
        cin >> a[i];
    }
    int large,index;
    for (int i = n-1; i > 0; i--)
    {
        large = a[0];
        index = 0;
        for (int j = 1; j < i; j++)
        {
            if (a[j] > large)
            {
                large = a[j];
                index = j;
            }
        }
        a[index] = a[i];
        a[i] = large;
    }
    cout << endl;
    for (int i = 0; i <= n - 1; i++)
    {
        cout << a[i] << " ";
    }
}