
#include <iostream>
#include <algorithm>

using namespace std;

void findelements(int arr1[], int size1, int arr2[], int size2) 
{
    int i = 0, j = 0;

    while (i < size1 && j < size2) 
    {
        if (arr1[i] == arr2[j]) 
        {
            cout << arr1[i] << " ";
            ++i;
            ++j;
        } 
        else if (arr1[i] < arr2[j]) 
        {
            ++i;
        } 
        else 
        {
            ++j;
        }
    }
}

void find()
{
        int size1, size2;
        cout << "Enter the size of the first array::"<<endl;
        cin >> size1;
        int arr1[size1];
        cout << "Enter elements for the first array::"<<endl;
        for (int i = 0; i < size1; ++i) 
        {
            cin >> arr1[i];
        }

        cout << "Enter the size of the second array::" <<endl;
        cin >> size2;
        int arr2[size2];
        cout << "Enter elements for the second array:;"<<endl;
        for (int i = 0; i < size2; ++i) 
        {
            cin >> arr2[i];
        }

        cout << "Common elements are::"<<endl;
        findelements(arr1, size1, arr2, size2);
        cout << endl;
        return ;
}

int main() 
{
    int testCases;
    cout << "Enter the number of test cases::"<<endl;
    cin >> testCases;

    for (int t = 0; t < testCases; ++t) 
    {
       cout<<"TestCase::"<<t+1<<endl;
       find();
    }
    return 0;
}
