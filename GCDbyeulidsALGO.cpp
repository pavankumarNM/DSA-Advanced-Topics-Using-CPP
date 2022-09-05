#include <iostream>
using namespace std;
int GCD(int a, int b)
{
    int rem = 0;
    while (b != 0)
    {
        rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}
int main()
{
    cout << GCD(20, 90);
    return 0;
}