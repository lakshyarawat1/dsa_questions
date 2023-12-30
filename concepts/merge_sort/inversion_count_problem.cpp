// Inversion Count for an array indicates – how far
//  (or close) the array is from being sorted. If the array
//  is already sorted, then the inversion count is 0, but if the array
//  is sorted in reverse order, the inversion count is the maximum. Given an array
//   arr[].The task is to find the inversion count of arr[].Where two elements arr[i] and
//   arr[j] form an inversion if a[i] > a[j] and i < j.

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>  arr, int s, int e)
{
    int mid = (s + e) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    // creating temp arrays
    int *first = new int[len1];
    int *second = new int[len2];

    // copy values
    int mainArrayIndex = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainArrayIndex++];
    }

    // merge two arrays
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainArrayIndex++] = first[index1++];
        }
        else
        {
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    while (index1 < len1)
    {
        arr[mainArrayIndex++] = first[index1++];
    }
    while (index2 < len2)
    {
        arr[mainArrayIndex++] = second[index2++];
    }
}

void mergeSort(vector<int> arr, int s, int e)
{

    // base case
    if (s >= e)
    {
        return;
    }

    int mid = (s + e) / 2;

    // sorting the left part
    mergeSort(arr, s, mid);

    // sorting the right part
    mergeSort(arr, mid + 1, e);

    merge(arr, s, e);
}

int main()
{

    vector<int> arr = {16, 21, 52, 23, 63, 12, 32};
    int size = arr.size();

    mergeSort(arr, 0 , size - 1);

    return 0;
}