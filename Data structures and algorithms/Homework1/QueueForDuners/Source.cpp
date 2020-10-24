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
    char* arr = new char[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    long min = 0;
    long max = 0;
    long range = 0;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == '-')
        {
            long tempMin = 0;
            long tempMax = 0;
            long tempRange = 0;
            tempMin = i;
            while (arr[i] == '-')
            {
                tempRange++;
                i++;
            }
            tempMax = i - 1;
            if (tempRange > range)
            {
                range = tempRange;
                max = tempMax;
                min = tempMin;
            }
        }
    }
    if (range == 0)
    {
        cout << "-1";
    }
    else if (max + 1 >= n || min - 1 < 0)
    {
        cout << range - 1;
    }
    else
    {
        if (range%2==0)
        {
            cout << range / 2 - 1;
        }
        else
        {
            cout << range / 2 ;

        }


    }
    delete[] arr;
}