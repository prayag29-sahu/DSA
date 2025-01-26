#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i <= n-1;i++)
    {
        cin >> a[i];
    }
    int check=1;
    for (int i = 0; i <= n-1 && check==1;i++)
    {
        check = 0;
        for (int j = 0; j < n - i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                check = 1;
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    cout << endl;
    for (int i = 0; i <= n-1; i++)
    {
        cout<< a[i]<<" ";
    }
}