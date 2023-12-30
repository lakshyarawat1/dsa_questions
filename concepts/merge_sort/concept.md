# Merge Sort

Merge sort is a divide-and-conquer algorithm that sorts a list by repeatedly dividing it into two halves, sorting each half, and then merging the sorted halves back together.

## Algorithm

1. Divide the unsorted list into two halves.
2. Recursively sort each half.
3. Merge the sorted halves back together.

## Applications

- Sorting large datasets efficiently.
- External sorting when the data doesn't fit into memory.
- Parallel processing and distributed systems.

## Pros

- Stable sorting algorithm.
- Guarantees worst-case time complexity of O(n log n).
- Efficient for sorting large datasets.
- Can be easily parallelized.

## Cons

- Requires additional memory space for merging.
- Not as efficient for small datasets compared to other sorting algorithms like insertion sort.
- Recursive nature can lead to stack overflow for very large datasets.
