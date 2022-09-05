
#include <iostream>
using namespace std;
int main()
{
  int i, a = 10, b = 20;
  // cout<<"enter a b"<<endl;
  // cin>>a>>b;
  for (int num = a; i <= b; num++)
  {
    for (i = 2; i < num; i++)
    {
      if (num % i == 0)
      {
        break;
      }
    }
    if (i == num)
    {
      cout << "the num " << num << " is prime" << endl;
    }
  }

  return 0;
}