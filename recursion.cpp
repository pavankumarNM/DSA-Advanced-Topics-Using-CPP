#include <iostream>
using namespace std;
int sum(int n)
{
    if (n == 1)
        return 1;
    return n + sum(n - 1);
}
int powP(int n, int p)
{
    if (p == 0)
        return 1;
    return n * powP(n, p - 1);
}
int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}
int fibonacci(int n)
{
    int sum;
    if (n == 1 || n == 0)
    {
        return n;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}
int main()
{
    int n;
    cin >> n;
    // int p;
    // cin>>p;
    // cout<<" Sum is "<<sum(n);
    // cout<<" power of p is "<<powP( n,p);
    // cout<<factorial(n);
    cout << fibonacci(n);
    return 0;
}