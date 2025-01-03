#include <iostream>
#define Max 100
using namespace std;

int main()
{
    int n, i, small=0;
    cin >> n;
    int a[Max];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (i = 0; i < n; i++)
    {
        if (a[i] <= a[small])
        {
            a[small] = a[i];
        }
    }
    cout << "smallest element is " << a[small];
    small++;
    /*
        cout << "Array element : ";
        for (i = 0; i < n; i++)
        {
            cout << a[i] << endl;
        }
    */
}