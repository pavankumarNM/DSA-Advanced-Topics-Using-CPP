#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int max = INT_MIN;
    int n;
    cout << "enter the array size" << endl;
    cin >> n;
    int arr[n];
    cout << "enter the elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {

        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    cout << "max interger in array is " << max;

    return 0;
}