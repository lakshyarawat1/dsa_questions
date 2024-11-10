# Greedy Algorithm

Greedy algorithm is a problem-solving technique that makes the best local choice at each step in the hope of finding the global optimal solution.

Some examples are :

- Dijkstra's algorithm: Finds the shortest path between two nodes in a graph. It repeatedly chooses the shortest edge available for current node.

- Kruskal's algorithm : Finds the minimum spanning tree if the graph. Repeatedly chooses the edge with minimum weight that does not create a circle.

- Fractional Knapsack problem : Involves selecting items with the highest value-to-weight ratio to fill the knapsack with a limited capacity. Greedy algorithm selects item in decreasing order of their value-to-weight ratio until the knapsack fills.

- Scheduling and resource allocation.

- Coin change problem

- Huffman Coding.

## Working 

- Greedy algorithms work by making the best local choice at each step in the hope of finding the global optimal solution.

- Steps include :

    - Initial State.
    - Evaluate all possible choices you can make from the current state.
    - Choose the best/optimal solution at that moment, regardless of future consequences. This is the 'greedy' part.
    - Repeat the steps until you reach the goal state or no further progress is possible.

## Pros and Cons

### Pros

- Simple and easy to understand.
- Fast execution time.
- Effecient for certain problems.
- Intuitive and easy to explain.
- Can be used as building blocks for more complex algorithms.

### Cons

- Not always optimal.
- Difficult to prove opitmality.
- Sensitive to input order.
- Limited applicability.

## Questions 

- [Split a string in balanced strings](/concepts/greedy/split-a-string-in-balanced-strings.cpp)