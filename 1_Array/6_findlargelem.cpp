#include <iostream>
#define Max 100
using namespace std;

int main()
{
    int n, i, large = 0;
    cin >> n;
    int a[Max];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (i = 0; i < n; i++)
    {
        if (a[i] >= a[large])
        {
            a[large] = a[i];
        }
    }
    cout << "Largest element is " << a[large];
    /*
        cout << "Array element : ";
        for (i = 0; i < n; i++)
        {
            cout << a[i] << endl;
        }
    */
}