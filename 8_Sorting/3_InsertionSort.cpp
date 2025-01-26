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
    int temp = 0,j;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < a[i - 1])
        {
            j = i;
            temp = a[i];
            do{
                a[j] = a[j - 1];
                j--;
            } while (j > 0 && a[j - 1] > temp);
            a[j] = temp;
        }
    }
    cout << endl;
    for (int i = 0; i <= n - 1; i++)
    {
        cout << a[i] << " ";
    }
}