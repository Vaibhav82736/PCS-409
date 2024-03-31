#include <iostream>
using namespace std;
void selectionSort()
{
    int size;
    int swaps = 0;
    int com = 0;
    int i, j, min;
    cout<<"Enter size of array::"<<endl;
    cin>>size;
    int arr[size];
    cout<<"Enter element::"<<endl;
    for(i=0;i<size;i++)
    {
        cin>>arr[i];
    }  
	for (i = 0; i < size - 1; i++) 
    { 
		min = i; 
		for (j = i + 1; j < size; j++) 
        { 
			if (arr[j] < arr[min]) 
				min = j;
            com++; 
		} 
		if (min != i) 
			swap(arr[min], arr[i]);
        swaps++;
	} 
    cout<<"Elements after sorting::"<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<endl;
    }
    cout<<"Number of comparisons::"<<com<<endl;
    cout<<"Number of swaps::"<<swaps<<endl;

}

int main()
{
    int testcases;
    cout<<"Number of test cases::"<<endl;
    cin>>testcases;
    for(int i=0;i<testcases;i++)
    {
        cout<<"Testcase "<<i+1<<endl;
        selectionSort();
    } 

}