#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n;
    cout << "enter n" << endl;
    cin >> n;
    int original = n;
    int sum = 0;
    while (n > 0)
    {
        int lastdigit = n % 10;
        sum += pow(lastdigit, 3);
        n = n / 10;
    }
    if (original == sum)
    {
        cout << "success" << endl;
    }
    else
    {
        cout << "failure";
    }
    return 0;
}
// armstrong search not have a time to enter what is the definition of a armstrong num in this shitty code
