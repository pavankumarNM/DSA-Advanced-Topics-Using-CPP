#include <iostream>
using namespace std;

int finder(int arr[], int key, int n)
{
    int s = 0, e = n;
    while (s <= e)
    {

        int mid = (s + e) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }

        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }

    return -1;
}
int main()
{
    int key, n;

    // cout<<"enter the length of the array"<<endl;
    cin >> n;
    int arr[n];
    // cout<<"enter elements"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // cout<<"enter the key to find"<<endl;
    cin >> key;
    cout << finder(arr, key, n);

    return 0;
}