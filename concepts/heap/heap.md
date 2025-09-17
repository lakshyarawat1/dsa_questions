# Heap

## Prerequisites

- Binary tree
- Array representation of Binary Tree
- Complete binary tree

## Definition

- Heap is a complete binary tree
- Max heaps have all children smaller than root
- Min heap have all children bigger than root
- Duplicates are allowed in children

## Insertion Operation

- Insertion is always done on the last free space on the array, i.e. at the bottom on the heap.
- Then heap is re-adjusted to comply with min/max rules.
- Time complexity for insertion is O(log n).
- Adjustment is ddone upwards.

## Deletion operation

- Only root element should be deleted.
- Max heap always gives the biggest element.
- Min heap always gives the smallest element.
- After the root is deleted, the last element / last leaf in the heap will take its place.
- Then adjusted as per heap type.
- Adjustment is done from root to leaf.
- Time complexity for deletion - O(log n)

## Heapify

- Fill all the elements in the heap without considering the rules.
- Take the downward approach, but starting from the last element of the heap.
- When there are children of the node, compare the children as which one is bigger.
- Compare the bigger child with the parent node, if child is bigger it needs to be adjusted / swapped.
- Recursively do this for all nodes.
- Time complexity - O(n)
- Without heapify, inserting n elements will take O(n log n) time.

## Pseudocode for Heapify

```cpp
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

