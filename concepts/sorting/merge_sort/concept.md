# Merge Sort

## Introduction

- Divide-and-conquer algorithm
- Recursive algorithm that continually splits a list in half

### Process

1. Divide the unsorted list into `n` sublists, each containing one element
2. Repeatedly merge sublists to produce new sorted sublists until there is only one sublist remaining
3. The final sublist is the sorted list

### Complexity

- Time complexity: O(n log n)
- Space complexity: O(n) 

## Code 

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // for std::merge and std::copy

void merge(std::vector<int>& arr, int left, int mid, int right) {
    // Temporary vectors for the two halves
    std::vector<int> leftVec(arr.begin() + left, arr.begin() + mid + 1);
    std::vector<int> rightVec(arr.begin() + mid + 1, arr.begin() + right + 1);

    // Merge the two halves back into the original array 
    int i = 0, j = 0, k = left;

    while (i < leftVec.size() && j < rightVec.size()) {
        // compares all elements and sorts them
        if (leftVec[i] <= rightVec[j]) {
            arr[k++] = leftVec[i++];
        } else {
            arr[k++] = rightVec[j++];
        }
    }

    // Copy any remaining elements from leftVec
    while (i < leftVec.size()) {
        arr[k++] = leftVec[i++];
    }

    // Copy any remaining elements from rightVec
    while (j < rightVec.size()) {
        arr[k++] = rightVec[j++];
    }
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively sort the two halves until only one element is left in each array
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main() {
    std::vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    mergeSort(arr, 0, arr.size() - 1);

    std::cout << "Sorted array: ";
    for (const int& num : arr) {
        std::cout << num << " ";
    }

    return 0;
}

```

## Optimization

- Switch to insertion sort for small sublists
- Avoid copying elements if the two halves are already sorted
- Skip the merge step if the largest element in the left half is less than the smallest element in the right half

## Pros and Cons

### Pros

- Consistent O(n log n) time complexity
- Efficient for large datasets
- Stable

### Cons

- Not in-place
- Slower

## Stability and In-Place 

- Merge sort is stable
- Not in-place, requires additional memory for the temporary arrays

## Use Cases

- When stability is required
- For large datasets
- Sorting linked lists, where extra space is not a drawback.

