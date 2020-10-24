#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    long n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    long m;
    cin >> m;
    vector<int> arr2;
    for (int i = 0; i < m; i++)
    {
        int temp2;
        cin >> temp2;
        arr.push_back(temp2);
    }

    
    unique(arr.begin(),arr.end());
    unique(arr2.begin(), arr2.end());


    int res = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr2.size(); j++)
        {
            if (arr[i]==arr2[j])
            {
                res += arr[i];
                break;
            }
        }
    }

    cout << res;
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; 
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++)
    {
       
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
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
