# Insertion Sort

## Introduction

- Insertion Sort is a simple and intuitive sorting algorithm that builds a sorted array one element at a time.
- It is efficient for small data sets and mostly sorted arrays.
- The algorithm works by comparing each new element to the already sorted elements and inserting it into its correct position.

## Pseudocode

```py
function insertionSort(array):
    for i from 1 to length(array) - 1:
        key = array[i]
        j = i - 1
        while j >= 0 and array[j] > key:
            array[j + 1] = array[j]
            j = j - 1
        array[j + 1] = key
    return array
```

## Time Complexity

- Best Case: O(n) - occurs when the array is already sorted.
- Average Case: O(n^2) - occurs for random order of elements.
- Worst Case: O(n^2) - occurs when the array is sorted in reverse order.

## Space Complexity

- O(1) - Insertion Sort is an in-place sorting algorithm, requiring only a constant amount of additional memory space.

## Stability

- Insertion Sort is a stable sorting algorithm, meaning that it preserves the relative order of equal elements in the sorted output.

