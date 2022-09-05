#include <iostream>
using namespace std;
int main()
{
    int rows = 5, columns = 6;

    // simple rows and colums patterns
    //  cout << "enter the number of rows and columns" << endl;
    // cin >> rows >> columns;
    //  for (int i = 0; i < rows; i++)
    //   {
    //      for (int j = 0; j < columns; j++)
    //     {
    //        cout << '*'<<" ";
    //    }
    //    cout<<endl;
    //  }

    //  hollow patterns int rows, columns;
    /* cout << "enter the number of rows and columns" << endl;
    cin >> rows >> columns;
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= columns; j++)
        {
            if (j == 1 || j == columns)
            {
                cout << '*';
            }
            else if (i == 1 || i == rows)
            {
                cout << '*';
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }*/

    //  inverted half pyramid
    /*   int n;
    cout<<"enter the number n "<<endl;
    cin>>n;

    for (int i = n; i>=1; i--)
    {
        for (int j = 1; j<=i; j++)
        {
           cout<<"*";
        }
        cout<<endl;

    }*/

    // straight half pyramid
    /* int n;
    cout<<"enter the number n "<<endl;
    cin>>n;

    for (int i = 1; n>=i; i++)
    {
        for (int j = i; i>=j; j++)
        {
           cout<<"*";
        }
        cout<<endl;

    }*/

    // half pyramid after 180' rotation
    /* int n;
     cout << "enter the number n " << endl;
     cin >> n;

     for (int i = 1; n >= i; i++)
     {
         for (int j = 1; j <= n; j++)
         {
             if (j <= n - i)
             {
                 cout <<" ";
             }
             else
             {
                 cout << "*";                    // cout<<"* "    this one is for triangle of tip edge
             }
         }

         cout << endl;
     }*/

    return 0;
}