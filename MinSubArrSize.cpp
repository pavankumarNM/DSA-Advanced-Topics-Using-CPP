#include<bits/stdc++.h>
using namespace std;

void MinSubArrSize(int arr[],int n,int x){
    int minLength=n+1;int start=0,end=0;int sum=0;
    
      while (end<n)
      {
        while (end<n && sum<=x)
        {
            sum+=arr[end++];
        }
        while (sum>x && start<n)
        {
            if (minLength>end-start)
            {
                minLength=end-start;
            }
            sum-=arr[start++];
        }
        
        
      }
      if (minLength == n+1)
      {
        cout<< " Solution  doesn't exist \n";
      }
      else
      {
        cout<<" The Minimum size of Subarray is "<<minLength<<endl;
      }
      
      
      
    
}

int main(){
    int arr[]={1,4,45,6,10,19};
    int x=51;
    int n=6;
    MinSubArrSize(arr,n,x);
    return 0;
}