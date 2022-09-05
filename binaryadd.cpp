#include <iostream>
using namespace std;
int reverse(int ans)
{
    int a = 0;
    int lastdigit;
    while (ans > 0)
        lastdigit = ans / 10;
    a = a * 10 + lastdigit;
    ans /= 10;
    return a;
}
int addB(int a, int b)
{
    int prec = 0, ans = 0;

    while (a > 0 && b > 0)
    {
        if ((a % 2 == 0) && (b % 2 == 0))
        {

            ans = ans * 10 + prec;
            prec = 0;
        }
        else if ((a % 2 == 0 && b % 2 == 1) || (a % 2 == 1 && b % 2 == 0))
        {
            if (prec == 1)
            {
                ans = ans * 10 + 0;
                prec = 1;
            }
            else
            {
                ans = ans * 10 + 1;
                prec = 0;
            }
        }
        else
        {
            ans = ans * 10 + prec;
            prec = 1;
        }
        a /= 10;
        b /= 10;
    }
    while (a > 0)
    {
        if (prec == 1)
        {
            if (a % 2 == 1)
            {
                ans = ans * 10 + 0;
                prec = 1;
            }
            else
            {
                ans = ans * 10 + 1;
                prec = 0;
            }
        }
        else
        {
            ans = ans * 10 + (a * 2);
        }
        a /= 10;
    }

    while (b > 0)
    {
        if (prec == 1)
        {
            if (b % 2 == 1)
            {
                ans = ans * 10 + 0;
                prec = 1;
            }
            else
            {
                ans = ans * 10 + 1;
                prec = 0;
            }
        }
        else
        {
            ans = ans * 10 + (b * 2);
        }
        b /= 10;
    }
    if (prec == 1)
    {
        ans = ans * 10 + 1;
    }

    return reverse(ans);
}

int32_t main()
{
    int a, b;
    cout << "enter n" << endl;
    cin >> a >> b;
    cout << addB(a, b) << endl;
    return 0;
}