#include <iostream>
#define Max 100
using namespace std;

int main()
{
    int n, i, search;
    cin >> n;
    int a[Max];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> search;
    for (i = 0; i < n; i++)
    {
        if (a[i] == search)
        {
            cout << "The element " << search << " at index no. " << i << endl;
        }
    }
    /*
        cout << "Array element : ";
        for (i = 0; i < n; i++)
        {
            cout << a[i] << endl;
        }
    */
}