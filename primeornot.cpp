#include <iostream>
using namespace std;
int main()
{
  int num = 17;
  // cout<<"enter the number "<<endl;
  // cin>>num;
  for (int i = 2; i < num; i++)
  {
    if (num % i == 0)
    {
      cout << "the num " << num << " is not prime  it is divisible by " << i << endl;
      break;
    }
    else if (i == (num - 1))
    {
      cout << "the number " << num << " is prime" << endl;
    }
  }

  return 0;
}