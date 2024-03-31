#include <iostream>
using namespace std;
int binarySearch(int arr[], int l, int r, int x)
{
	if (r < l)
		return -1;
	int mid = l + (r - l) / 2;
	if (arr[mid] == x)
		return mid;
	if (arr[mid] > x)
		return binarySearch(arr, l, mid - 1, x);
	return binarySearch(arr, mid + 1, r, x);
}
int countOccurrences(int arr[], int n, int x)
{
    int ind = binarySearch(arr, 0, n - 1, x);
    if (ind == -1)
        return 0; 
    int count = 1; 
    int left = ind - 1;
    while (left >= 0 && arr[left] == x)
    {
        count++;
        left--;
    }
    int right = ind + 1;
    while (right < n && arr[right] == x)
    {
        count++;
        right++;
    }
    return count;
}
int main()
{
	int t,n,i,j,x;
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
	    cout<<"enter key";
	    cin>>x;
	    cout << countOccurrences(a, n, x);
	}
	return 0;
}