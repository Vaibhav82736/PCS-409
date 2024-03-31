
#include<iostream>
using namespace std;
int linearsearch(int a[],int n,int key)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==key)
		{
			return i;
		}
	}
	return -1;
}
int main()
{
	int m,j;
	cout<<"enter number";
	cin>>m;
	for(j=0;j<m;j++)
	{
		int n,key;
		cout<<"enter size";
		cin>>n;
		cout<<"enter key";
		cin>>key;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		int x=linearsearch(a,n,key);
		if(x==-1)
		{
			cout<<"Not present";
		}
		else
		{
			cout<<"Present"<<x+1;
		}
	}
	return 0;
}
