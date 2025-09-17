# Heap Sort

## Prequisites

- Understanding of binary trees and complete binary trees.
- Array representation of binary heaps.
- Operations on heaps (insertion, deletion, heapify).

## Introduction

- Uses a property of max / min heaps that it deletes the largest / smallest element in O(log n) time.
- First create a min / max heap from the input data.
- Then repeatedly delete the root of the heap (the largest / smallest element) and reconstruct the heap until all elements are deleted.
- The deleted elements form a sorted array.

## Pseudocode

```py
function heapSort(array):
    n = length(array)

    // Build a max heap
    for i from floor(n / 2) - 1 down to 0:
        heapify(array, n, i)

    // One by one extract elements from heap
    for i from n - 1 down to 0:
        swap(array[0], array[i]) // Move current root to end
        heapify(array, i, 0) // call max heapify on the reduced heap

    return array
function heapify(array, n, i):
    largest = i // Initialize largest as root
    left = 2 * i + 1 // left = 2*i + 1
    right = 2 * i + 2 // right = 2*i + 2
    if left < n and array[left] > array[largest]:
        largest = left
    if right < n and array[right] > array[largest]:
        largest = right
    if largest != i:
        swap(array[i], array[largest])
        heapify(array, n, largest)
```

## Time Complexity

- Best Case: O(n log n) - occurs regardless of the initial order of elements.
- Average Case: O(n log n) - occurs for random order of elements.
- Worst Case: O(n log n) - occurs regardless of the initial order of elements.

## Space Complexity

- O(1) - Heap Sort is an in-place sorting algorithm, requiring only a constant amount of additional memory space.

## Stability

- Heap Sort is not a stable sorting algorithm, meaning that it does not preserve the relative order of equal elements in the sorted output.

