
#include <iostream>
using namespace std;
int kthSmallest(int arr[], int n, int k) 
{
	int max_element = arr[0];
	for (int i = 1; i < n; i++) 
    {
		if (arr[i] > max_element) 
        {
			max_element = arr[i];
		}
	}
	int freq[max_element + 1] = {0};
	for (int i = 0; i < n; i++) 
    {
		freq[arr[i]]++;
	}
	int count = 0;
	for (int i = 0; i <= max_element; i++) 
    {
		if (freq[i] != 0) 
        {
			count += freq[i];
			if (count >= k) 
            {
				return i;
			}
		}
	}
	return -1;
}

void sort() 
{
    int size;
    int i,k,x;
    cout << "Enter the size of the array::" << endl;
    cin >> size;
    int arr[size];
    cout << "Enter the elements::" << endl;
    for (i = 0; i < size; i++) 
    {
        cin >> arr[i];
    }
    cout << "Enter the k::" << endl;
    cin >> k;
    x = kthSmallest(arr,size,k);
    if(x==-1)
    {
        cout<<"Error"<<endl;
        return;
    }
    cout << endl << "Kth smallest element::" << x << endl;
    return;
}

int main() 
{
    int testcases;
    cout << "Enter the number of testcases::" << endl;
    cin >> testcases;

    for (int i = 0; i < testcases; i++) 
    {
        cout << endl << "Testcase " << i + 1 << endl;
        sort();
    }
return 0;
}
