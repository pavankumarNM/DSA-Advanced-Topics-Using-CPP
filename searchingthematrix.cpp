#include <bits/stdc++.h>
using namespace std;
int main()
{
    int row, col;
    cin >> row >> col;
    int mat[row][col];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> mat[i][j];
        }
    }
    int key;
    cin >> key;
    int r = 0, c = col - 1;
    bool flag = false;
    while (r < row && c >= 0)
    {
        if (mat[r][c] == key)
        {
            flag = true;
        }
        if (mat[r][c] > key)
        {
            c--;
        }
        else
        {
            r++;
        }
    }
    if (flag)
    {
        cout << "Element Found\n";
    }
    else
    {
        cout << "Element Not Found\n";
    }

    return 0;
}