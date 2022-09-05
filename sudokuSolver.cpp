#include <bits/stdc++.h>
using namespace std;

void helper(int r, int c, vector<vector<char>> &a, map<pair<int, int>, map<int, int>> &mp, vector<map<int, int>> &row, vector<map<int, int>> &col)
{
    if (r == 9)
    {
        for (auto it : a)
        {
            for (auto i : it)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    if (c == 9)
    {
        helper(r + 1, 0, a, mp, row, col);
        return;
    }
    if (a[r][c] != '.')
    {
        helper(r, c + 1, a, mp, row, col);
        return;
    }

    for (int i = 1; i <= 9; i++)
    {
        int rw = r / 3;
        int cl = c / 3;
        for (int j = 1; j <= 9; j++)
        {
            if (!mp[{rw, cl}][a[i][j]] && !row[i][a[i][j]] && !col[j][a[i][j]])
            {
                mp[{rw, cl}][a[i][j]] = 1;
                row[i][a[i][j]] = 1;
                col[j][a[i][j]] = 1;
                a[i][j] = i + '0';
                helper(r, c + 1, a, mp, row, col);
                mp[{rw, cl}][a[i][j]] = 0;
                row[i][a[i][j]] = 0;
                col[j][a[i][j]] = 0;
                a[i][j] = '.';
            }
        }
    }
}

void sudokuSolver(vector<vector<char>> &a)
{
    map<pair<int, int>, map<int, int>> mp;
    vector<map<int, int>> row(9);
    vector<map<int, int>> col(9);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (a[i][j] != '.')
            {
                mp[{i / 3, j / 3}][a[i][j] - '0'] = 1;
                row[i][a[i][j] - '0'] = 1;
                col[j][a[i][j] - '0'] = 1;
            }
        }
    }
    helper(0, 0, a, mp, row, col);
}

int main()
{
    vector<vector<char>> a;
    a = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}

    };
    sudokuSolver(a);
    return 0;
}