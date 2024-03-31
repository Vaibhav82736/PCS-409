#include <iostream>
using namespace std;
void insertionSort()
{
    int size;
    int key;
    int shift = 0;
    int com = 0;
    cout<<"Enter size of array::"<<endl;
    cin>>size;
    int arr[size];
    cout<<"Enter element::"<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    for (int i = 1; i < size; i++) 
    {
        key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
            shift ++ ;
            com ++ ;

        }
        arr[j + 1] = key;
        shift ++ ;
    }
    cout<<"Elements after sorting::"<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<endl;
    }
    cout<<"Number of comparisons::"<<com<<endl;
    cout<<"Number of shifts::"<<shift<<endl;

}

int main()
{
    int testcases;
    cout<<"Number of test cases::"<<endl;
    cin>>testcases;
    for(int i=0;i<testcases;i++)
    {
        cout<<"Testcase "<<i+1<<endl;
        insertionSort();
    } 

}