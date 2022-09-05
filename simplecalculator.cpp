#include <iostream>
using namespace std;
int main()
{
    int n1, n2;
    cout << "enter the number n1 and n2" << endl;
    cin >> n1 >> n2;
    char c;
    cout << "enter the operator '+' '-' '*' '/' " << endl;
    cin >> c;
    switch (c)
    {
    case '+':
        cout << n1 + n2;
        break;
    case '-':
        cout << n1 - n2;
        break;
    case '*':
        cout << n1 * n2;
        break;
    case '/':
        cout << n1 / n2;
        break;

    default:
        cout << "choose operator correctly";
        break;
    }
    return 0;
}