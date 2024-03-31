#include <iostream>
 using namespace std;
 
int com=0;
int in=0;
 
void Merge(int a[], int low, int high, int mid)
{
    int i, j, k, temp[high-low+1];
    i = low;
    k = 0;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            temp[k] = a[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = a[j];
            k++;
            j++;
            in=in+((mid-i)+1);
        }
        com++;
    }
    while (i <= mid)
    {
        temp[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        temp[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i <= high; i++)
    {
        a[i] = temp[i-low];
    }
}
 
void MergeSort(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        MergeSort(a, low, mid);
        MergeSort(a, mid+1, high);
        Merge(a, low, high, mid);
    }
}

void sort()
{
    int size;
    int i;
    cout<<"Enter the size of the array::"<<endl;
    cin>>size;
    int arr[size];
    cout<<"Enter the elements::"<<endl;
    for(i=0;i<size;i++)
    {
        cin>>arr[i];    
    }
    MergeSort(arr,0,size-1);
    cout<<"Elements after sorting::"<<endl;
    for(i=0;i<size;i++)
    {
        cout<<arr[i]<<"  ";    
    }
    cout<<endl<<"Number of comparisons::"<<com<<endl;
    cout<<"Number of inversions::"<<in<<endl;
    return ;
    
}
 
int main()
{
    int testcases,i;
    cout<<"Enter the number of testcases::"<<endl;
    cin>>testcases;
    for(i=0;i<testcases;i++)
    {
        cout<<endl<<"Testcases"<<i+1<<endl;
        sort();
    }
    return 0;
}