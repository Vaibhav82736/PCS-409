
#include <bits/stdc++.h>
using namespace std;
void count()
{
    int size,i,j,k,x=0,sum;
    cout<<"Enter the number of element::"<<endl;
    cin>>size;
    int arr[size];
    cout<<"Enter the elements::"<<endl;
    for ( i = 0; i < size; i++)
   {
       cin>>arr[i];
   }
   cout<<"Enter sum::"<<endl;
    cin>>k;
   sort(arr,arr+size);
   i=0;
   j=size-1;
   cout<<"Answer ::"<<endl;
   while(i<j)
   {
       sum=arr[i]+arr[j];
       if(sum==k)
       {
          cout<<arr[i]<<" "<<arr[j]<<endl;
          x++;
          i++;
          j--;
       }
       else if(sum>k)
       {
           j--;
       }
       else
       {
           i++;
       }
   }
   if(x==0)
   {
       cout<<"No pair found"<<endl;
   }
   return;
}
int main()
{
   int Testcase,i;
   cout<<"Enter the number of testcases::"<<endl;
   cin >>Testcase ;
   for(i=0;i<Testcase;i++)
   {
       cout<<endl<<"Testcase "<<i+1<<endl;
       count();
   }
   return 0;
}
