# Quick Sort

- Divide and Conquer algorithm.
- Uses partitioning
- Uses recursion

## Working

- Take any element as pivot
- Initialize i=0, j=end of list
- swap i and j elements if, arr[i] > pivot and arr[j] < pivot.
- Stop when j>i
- Pivot element is sorted now.
- Repeat the process recursively.

## Time complexity

- O(n log n) : Best Case, when pivot is at the middle of the list
- O(n^2) : Worst Case, when list is already sorted. Partitioning happens at the start of the list.

