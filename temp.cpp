#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ll long long
const int N = 1e5 + 2, M = 1e9 + 7;
int hn = 34323;



int main()
{
    int t = 25;
    while (--t)
    {
        int n;
        cin >> n;
        if (n == hn)
        {
            cout <<"Congragulations the Hidden Number is " << n << endl;
        }

        if (n < hn)
        {
            cout << "less than " << n << " \n";
            continue;
            
        }
        else{
        cout << "greater than " << n;
        }
    }

    return 0;
}