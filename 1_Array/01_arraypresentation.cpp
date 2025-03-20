#include <iostream>
#define Max 100
using namespace std;

int main()
{
    int n, i;
    cin >> n;
    int a[Max];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Array element : ";
    for (i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
}
