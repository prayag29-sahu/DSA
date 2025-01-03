#include <iostream>
#define Max 100
using namespace std;

int main()
{
    int n, i, pos;
    cin >> n;
    int a[Max];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> pos;
    if (pos >= n || pos < 0)
    {
        cout << "invalid";
    }
    else
    {
        for (i = pos; i < n;i++)
        {
            a[i] = a[i + 1];
        }
        n--;
    }
    cout << "Array element : ";
    for (i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
}