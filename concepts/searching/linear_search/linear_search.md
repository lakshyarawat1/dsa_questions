# Linear Search

## Definition

- Linear search is a simple searching algorithm that checks each element in a list sequentially until the desired element is found or the end of the list is reached.
- It is also known as sequential search.

## Advantages

- Simple to implement and understand.
- Does not require the list to be sorted.
- Works well for small or unsorted datasets.

## Disadvantages

- Inefficient for large datasets, as it may require checking every element.

## Pseudocode

```py
function linearSearch(array, target):
    for i from 0 to length(array) - 1:
        if array[i] == target:
            return i // Target found at index i
    return -1 // Target not found
```

## Time Complexity

- Best Case: O(1) - occurs when the target element is the first element in the list.
- Average Case: O(n) - occurs when the target element is located in the middle of the list.
- Worst Case: O(n) - occurs when the target element is the last element in the list or not present at all.

## Space Complexity

- O(1) - Linear search requires a constant amount of additional memory space, regardless of the input size.
