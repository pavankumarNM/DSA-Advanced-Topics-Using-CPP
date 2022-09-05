#include <iostream>
using namespace std;
int main()
{
  int a;
  cout << "enter a " << endl;
  cin >> a;
  if (a % 2 == 0)
  {
    cout << "a = " << a << " is even" << endl;
  }
  else
  {
    cout << "a = " << a << " is odd" << endl;
  }
  return 0;
}