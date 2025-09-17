# Selection Sort

## Introduction

- Selection Sort is a simple and intuitive sorting algorithm that divides the input list into two parts: a sorted and an unsorted region.
- Repeatedly selects the smallest element and sets it aside in the sorted region.

## Pseudocode

```
function selectionSort(array):
    n = length(array)
    for i from 0 to n - 1:
        minIndex = i
        for j from i + 1 to n - 1:
            if array[j] < array[minIndex]:
                minIndex = j
        if minIndex != i:
            swap(array[i], array[minIndex])
    return array
```

## Time Complexity

- Best Case: O(n^2) - occurs regardless of the initial order of elements.
- Average Case: O(n^2) - occurs for random order of elements.
- Worst Case: O(n^2) - occurs regardless of the initial order of elements.

## Space Complexity

- O(1) - Selection Sort is an in-place sorting algorithm, requiring only a constant amount of additional memory space.

## Stability

- Selection Sort is not a stable sorting algorithm, meaning that it does not preserve the relative order of equal elements in the sorted output.