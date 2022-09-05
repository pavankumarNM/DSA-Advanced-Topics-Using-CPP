#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>> maxHP;

priority_queue<int, vector<int>, greater<int>> minHP;

void insert(int num)
{
    if (maxHP.size() == minHP.size())
    {
        if (maxHP.size() == 0)
        {
            maxHP.push(num);
            return;
        }
        else
        {
            if (maxHP.top() > num)
            {
                minHP.push(num);
            }
            else
            {
                maxHP.push(num);
            }
        }
    }
    else
    {
        if (maxHP.size() > minHP.size())
        {
            if (num <= maxHP.top())
            {
                minHP.push(maxHP.top());
                maxHP.pop();
                maxHP.push(num);
            }
            else
            {
                minHP.push(num);
            }
        }
        else
        {
            if (num >= minHP.top())
            {
                maxHP.push(minHP.top());
                minHP.pop();
                minHP.push(num);
            }
            else
            {
                maxHP.push(num);
            }
        }
    }
}

double HeapMedian()
{
    if (maxHP.size() == minHP.size())
    {
        return (maxHP.top() + minHP.top()) / 2.0;
    }
    else
    {
        if (maxHP.size() > minHP.size())
        {
            return maxHP.top();
        }
        else
        {
            return minHP.top();
        }
    }
}

int main()
{

    insert(10);
    cout << HeapMedian() << endl;
    insert(15);
    cout << HeapMedian() << endl;
    insert(21);
    cout << HeapMedian() << endl;
    insert(30);
    cout << HeapMedian() << endl;
    insert(18);
    cout << HeapMedian() << endl;
    insert(19);
    cout << HeapMedian() << endl;
    return 0;
}