#include <bits/stdc++.h>
using namespace std;

void subarrayDivbyK(vector<int> arr, int k)
{
    int sum = 0;
    pair<int, int> ans;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    bool found = false;
    if (sum % 3 == 0)
    {
        ans = make_pair(0, k - 1);
        found = true;
    }
    for (int j = k; j < arr.size(); j++)
    {
        if (found)
        {
            break;
        }
        sum = sum + arr[j] - arr[j - k];
        if (sum % 3 == 0)
        {
            ans = make_pair(j - k + 1, j);
            found = true;
        }
    }
    if (!found)
    {
        ans = make_pair(-1, 0);
    }

    if (ans.first == -1)
    {

        cout << " Not Found \n";
    }
    else
    {
        for (int i = ans.first; i <= ans.second; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<int> arr = {84, 23, 45, 56, 82};
    int k = 3;
    subarrayDivbyK(arr, k);
    return 0;
}