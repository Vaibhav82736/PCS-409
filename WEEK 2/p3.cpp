#include<iostream>
using namespace std;
int count(int a[],int n,int key)
{
    int c=0,i,j;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]-a[j]==key||a[j]-a[i]==key)
            {
                c++;
            }
        }
    }
    return c;
}
int main()
{
    int t,n,i,j,key;
    cout<<"enter number of test cases";
    cin>>t;
    for(i=0;i<t;i++)
    {
        cout<<"enter size";
        cin>>n;
        int a[n];
        for(j=0;j<n;j++)
            cin>>a[j];
        cout<<"enter key";
        cin>>key;
        int x=count(a,n,key);
        cout<<x<<endl;
    }
    return 0;
}

