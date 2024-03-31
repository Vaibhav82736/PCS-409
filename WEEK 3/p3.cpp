#include <iostream>
using namespace std;

void merge(int arr[], int p, int q, int r) 
{
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];
  int i, j, k;
  i = 0;
  j = 0;
  k = p;
  while (i < n1 && j < n2) 
  {
    if (L[i] <= M[j]) 
    {
      arr[k] = L[i];
      i++;
    } else 
    {
      arr[k] = M[j];
      j++;
    }
    k++;
  }
  while (i < n1) 
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) 
  {
    arr[k] = M[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r) 
{
  if (l < r) 
  {
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

void Dup()
{
    int size;
    int flag =0;
    int i;
    cout<<"Enter size of array::"<<endl;
    cin>>size;
    int arr[size];
    cout<<"Enter element::"<<endl;
    for(i=0;i<size;i++)
    {
        cin>>arr[i];
    }  
	mergeSort(arr,0,size-1);
    for(i=0;i<size;i++)
    {
        if(arr[i]== arr[i+1] && i+1<size)
        {
            flag = 1;
        }
    }
    if(flag == 0)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
    }
    return;
}

int main()
{
    int testcases;
    cout<<"Number of test cases::"<<endl;
    cin>>testcases;
    for(int i=0;i<testcases;i++)
    {
        cout<<"Testcase "<<i+1<<endl;
        Dup();
    } 

}