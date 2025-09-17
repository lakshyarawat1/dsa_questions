# Binary Search

## Definition

- Binary search is an efficient searching algorithm that finds the position of a target value within a sorted array.
- It works by repeatedly dividing the search interval in half, eliminating half of the elements from consideration at each step.
- If the target value is less than the middle element, the search continues in the left half; if greater, it continues in the right half.
- This process is repeated until the target value is found or the search interval is empty.

## Prerequisites

- The array must be sorted prior to performing a binary search.
- Understanding of basic array indexing.

## Pseudocode

```py
function binarySearch(array, target):
    left = 0
    right = length(array) - 1
    while left <= right:
        mid = left + (right - left) // 2 // To avoid potential overflow
        if array[mid] == target:
            return mid // Target found at index mid
        else if array[mid] < target:
            left = mid + 1 // Search in the right half
        else:
            right = mid - 1 // Search in the left half
    return -1 // Target not found
```

## Time Complexity

- Best Case: O(1) - occurs when the target element is the middle element of the array.
- Average Case: O(log n) - occurs for random order of elements.
- Worst Case: O(log n) - occurs when the target element is not present in the array or is located at the ends of the array.

## Space Complexity

- O(1) - Binary search is an in-place searching algorithm, requiring only a constant amount of additional memory space.

## Advantages

- More efficient than linear search for large datasets due to its logarithmic time complexity.
- Reduces the number of comparisons needed to find the target element.

## Disadvantages

- Requires the array to be sorted beforehand, which may add overhead if the array is not already sorted.
- Not suitable for linked lists or data structures that do not allow random access.

## Variants

- Recursive Binary Search: A recursive implementation of the binary search algorithm.
- Exponential Search: A search algorithm that combines binary search with exponential search to find the range where the target may exist before performing binary search.
