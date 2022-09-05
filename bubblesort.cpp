#include <iostream>
using namespace std; // bubblesort algo
int main()
{
    int n;
    cout << "enter n" << endl;
    cin >> n;
    int arr[n];
    cout << "enter elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    /*
    int count=1;
    while (count<n)
    {
        for (int i = 0; i <n-count; i++)              by while loop
        {
            if (arr[i]>arr[i+1])
            {
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }

        }
        count++;

    }
    */
    for (int count = 1; count < n; count++) // by  for loop
    {
        for (int i = 0; i < n - count; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }

    cout << "printing elements in bubblesort algo" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }

    return 0;
}