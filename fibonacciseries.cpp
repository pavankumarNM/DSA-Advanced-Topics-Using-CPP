#include <iostream>
using namespace std;
void fib(int a)
{
    int n1 = 0, n2 = 1;
    int next;
    for (int i = 1; i <= a; i++)
    {
        cout << n1 << endl;
        next = n1 + n2;
        n1 = n2;
        n2 = next;
    }
}
int main()
{
    int m;
    cout << "entr m" << endl;
    cin >> m;
    fib(m);

    return 0;
}