#include <iostream>
using namespace std;
int main()
{
    int n, fac = 1;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        fac = fac * i;
    }
    cout << fac << endl;
    return 0;
}