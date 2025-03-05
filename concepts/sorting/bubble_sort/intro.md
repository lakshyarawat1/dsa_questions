# Bubble Sort

## Introduction

- Comparison-based sorting algorithm
- Smaller elements bubble to the top of the list
- Larger elements sink to the bottom with each pass

### Process

1. Compare each pair of adjacent elements
2. Swap them
3. Repeat until no swaps are needed
4. Repeat steps 1-3 until the list is sorted

### Complexity

- Time complexity: O(n^2)
- Space complexity: O(1)

## Optimization

- After each complete pass through the list, the largest element is guaranteed to be in its correct position
- No need to compare it again in subsequent passes
- If in a pass no swaps are made, the list is already sorted

## Code

```cpp

#include <iostream>
#include <vector>
#include <algorithm> // for std::swap

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();

    // Loop through each element in the vector
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;

        // Inner loop to compare adjacent elements
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Use STL swap to swap elements if they are in the wrong order
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // If no elements were swapped, the array is already sorted
        if (!swapped) {
            break;
        }
    }
}

int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    bubbleSort(arr);

    std::cout << "Sorted array: ";
    for (const int& num : arr) {
        std::cout << num << " ";
    }

    return 0;
}

```

## Pros and Cons

### Pros

- Simple and easy
- Useful for small datasets or nearly sorted datasets

### Cons

- Inefficient for large datasets
- Performs poorly to more advanced algorithms like quicksort or mergesort

## Use Cases

- Rarely used

## Stability and In-Place

- Bubble sort is stable, meaning it preserves the relative order of equal elements
- Bubble sort is an in-place sorting algorithm, meaning it uses a constant amount of extra space

## Questions

