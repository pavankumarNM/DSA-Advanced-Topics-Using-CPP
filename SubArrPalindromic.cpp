#include <bits/stdc++.h>
using namespace std;
bool isPalindromic(int num)
{
    int temp = num;
    int n = 0;
    while (temp > 0)
    {
        n = (n * 10) + temp % 10;
        temp = temp / 10;
    }
    if (n == num)
    {
        return true;
    }
    return false;
}
int SubArrPalindromic(vector<int> arr, int k)
{

    int num = 0;
    for (int i = 0; i < k; i++)
    {
        num = (num * 10) + arr[i];
    }
    if (isPalindromic(num))
    {
        return 0;
    }
    for (int j = k; j < arr.size(); j++)
    {
        num = (num % (int)pow(10, k - 1)) * 10 + arr[j];
        if (isPalindromic(num))
        {
            cout << (j - k - 1);
            return j - k + 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {1, 3, 7, 7, 5, 6, 5};
    int k = 3;
    int ans = SubArrPalindromic(arr, k);
    if (ans == -1)
    {
        cout << " Sub Array Not Found \n";
    }
    else
    {
        for (int i = ans; i < ans + k; i++)
        {
            cout << arr[i] << " ";
        }
    }

    return 0;
}