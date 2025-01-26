#include <iostream>
using namespace std;

void toh(int n, char f, char t, char aux)
{
    if (n == 1)
    {
        cout << "Move 1st disk from " << f << " to " << t<<endl;
        return;
    }
    toh(n - 1, f, aux, t);
    cout << "Move disk " << n << " from " << f << " to " << t<<endl;
    toh(n - 1, aux, t, f);
}
int main()
{
    int n;
    cin >> n;
    toh(n, 'A', 'C','B');

}