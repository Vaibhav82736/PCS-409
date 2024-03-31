#include<iostream>
using namespace std;
int find(int a[],int n)
{
    int i,j,k;
    for(i=0;i<n-2;i++)
    {
        for(j=i+1;j<n-1;j++)
        {
            for(k=j+1;k<n;k++)
            {
                if(a[i]+a[j]==a[k])
                {
                    cout<<i+1<<" "<<j+1<<" "<<k+1;
                    return 1;
                }
            }
        }
    }
    return -1;
}
int main()
{
    int n,t,i,j;
    cout<<"enter number of test cases";
    cin>>t;
    for(i=0;i<t;i++)
    {
        cout<<"enter size";
        cin>>n;
        int a[n];
        for(j=0;j<n;j++)
        {
            cin>>a[j];
        }
        int x=find(a,n);
        if(x==-1)
            cout<<"No sequence found";
    }
    return 0;
}