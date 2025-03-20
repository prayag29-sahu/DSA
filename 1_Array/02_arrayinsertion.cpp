#include <iostream>
#define Max 100
using namespace std;

int main()
{
    int n, i,pos,val;
    cin >> n;
    int a[Max];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> pos;
    if(pos>=n||pos<0)
    {
        cout << "invalid";
    }
    else
    {
        cin >> val;
        for (i = n; i > pos - 1;i--)
        {
            a[i] = a[i - 1];
        }
        a[pos] = val;
        n++;
    }

    cout << "Array element : ";
    for (i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
}
