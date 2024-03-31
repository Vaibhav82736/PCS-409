#include <iostream>
#include <cstdlib>
using namespace std;
int comparisons = 0;
int swaps = 0;

int partition(int arr[], int low, int high) 
{
    int pivotIndex = rand() % (high - low + 1) + low;
    int pivot = arr[pivotIndex];
    swap(arr[pivotIndex], arr[high]);
    int i = low - 1;
    for (int j = low; j < high; ++j) 
    {
        if (arr[j] < pivot) 
        {
            ++i;
            swap(arr[i], arr[j]);
            ++swaps;
        }
        ++comparisons;
    }
    swap(arr[i + 1], arr[high]);
    ++swaps;
    return i + 1;
}

void quickSort(int arr[], int low, int high) 
{
    if (low < high) 
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void sort() 
{
    int size;
    int i;
    cout << "Enter the size of the array::" << endl;
    cin >> size;
    int arr[size];
    cout << "Enter the elements::" << endl;
    for (i = 0; i < size; i++) 
    {
        cin >> arr[i];
    }
    quickSort(arr, 0, size - 1);
    cout << "Elements after sorting::" << endl;
    for (i = 0; i < size; i++) 
    {
        cout << arr[i] << "  ";
    }
    cout << endl << "Number of comparisons::" << comparisons << endl;
    cout << "Number of swaps::" << swaps << endl;
    return;
}

int main() {
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
