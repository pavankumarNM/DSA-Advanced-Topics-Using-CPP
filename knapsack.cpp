#include <iostream>
using namespace std;
int knapsack(int value[], int wt[], int W, int n)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (wt[n - 1] > W)
    {
        knapsack(value, wt, W, n - 1);
    }

    return max(knapsack(value, wt, W - wt[n - 1], n - 1) + value[n - 1], knapsack(value, wt, W, n - 1));
}

int main()
{
    int value[] = {100, 50, 150};
    int wt[] = {10, 20, 30};
    int W = 50;
    cout << knapsack(value, wt, 50, 3);
    return 0;
}