#include<iostream>
using namespace std;

int power(int x,int y)
{
    if(x==1||y==0)
        return 1;
    return (x * power(x, y - 1));
}
int main()
{
    int x, y,z;
    cin >> x >> y;
    z = power(x, y);
    cout << z;
}