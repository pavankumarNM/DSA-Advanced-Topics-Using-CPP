#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    cout << "enter the elements a,b,c" << endl;
    cin >> a >> b >> c;
    int d = (a > b && a > c) ? a : (b > c ? b : c);
    cout << d;
    return 0;
}