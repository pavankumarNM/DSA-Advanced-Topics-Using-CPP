#include <iostream>
using namespace std;
int getbit(int n, int pos)
{
    return ((n & (1 << pos)) != 0);
}
int setbit(int n, int pos)
{
    return (n | (1 << pos));
}
int clearbit(int n, int pos)
{
    int temp = ~(1 << pos);
    return (n & temp);
}
int updatebit(int n, int pos, int val)
{
    int temp = ~(1 << pos);
    n = (n & temp);
    return (n | val << pos);
}
bool ispower2(int n)
{
    return (n && !(n & n - 1));
}
int main()
{
    int n;
    cin >> n;
    // cout<<getbit(1001,1);
    // cout<<setbit(5,1);
    // cout<<clearbit(5,2);
    // cout<<updatebit(5,2,0);
    cout << ispower2(n);
    return 0;
}