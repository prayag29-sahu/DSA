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

    for (int i = n / 2; i > 0; i = i / 2)
    {

        for (int j = i; j < n; j++)
        {
            for (int k = j - i; k >= 0; k = k - i)
            {
                if (a[k + i] >= a[k])
                    break;
                else
                {
                    int temp = a[k];
                    a[k] = a[k + i];
                    a[k + i] = temp;
                }
            }
        }
    }
    cout << endl;
    for (int i = 0; i <= n - 1; i++)
    {
        cout << a[i] << " ";
    }
}