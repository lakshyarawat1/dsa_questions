# Graph

## Definition

- Graph is a collection of nodes and edges
- Edges connect nodes.
- Nodes can be represented as objects / nouns and edges as the relationships between those objects
- A hashmap can be used to store the next available node.

## Types

### Directed

- Edges have directions
- Only one way traversal


### Undirected 

- Edges don't have directions
- Two way traversal possible
- Typically represented as :
    ```js
        edges = [
            [i,j],
            [j,k],
            [k,l],
            [l,i]
        ]
    ```
- Means there is connection between i and j, j and k and so on.
- These are called edge lists.
- Can be changed to adjency lists for better understanding.

## Operations

### Depth First Traversal

- Move downwards whenever possible, if not, then move sideways.
- Start from top to bottom.
- All nodes may not be reached in a traversal, especially directed graphs.
- Uses a stack 
- Pushes all neighbours to the stack, and takes out one at a time and print it. Changes to the printed node as current
- Stack's LIFO properties automatically creates the depth first behavior.
- Code in Cpp : 
- ```cpp
  void depthFirstTraversal(Node* start) {
      stack<Node*> s;
      unordered_set<Node*> visited;
      s.push(start);
      visited.insert(start);
      
      while(!s.empty()) {
          Node* current = s.top();
          s.pop();
          cout << current->value << " ";
          
          for(auto neighbor : current->neighbors) {
              if(visited.find(neighbor) == visited.end()) {
                  s.push(neighbor);
                  visited.insert(neighbor);
              }
          }
      }
  }
  ```

### Breadth First Traversal 

- Move sideways first, horizontally.
- Will have different order than a depth first traversal.
- Immediate neighbours are first traversed, then moves to more depth.
- No direction is favoured, it evenly spreads to all directions.
- Uses a queue.
- Adds all the neighbors to the queue and pulls an element.
- Same as depth first traversal.
- FIFO properties of the queue gives the breadth first behavior.
- Code in Cpp :
```cpp
void breadthFirstTraversal(Node* start) {
    queue<Node*> q;
    unordered_set<Node*> visited;
    q.push(start);
    visited.insert(start);
    
    while(!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->value << " ";
        
        for(auto neighbor : current->neighbors) {
            if(visited.find(neighbor) == visited.end()) {
                q.push(neighbor);
                visited.insert(neighbor);
            }
        }
    }
}
```
- For graph traversals
- Time complexity is O(e) (e=no. of edges)
- Space complexity is O(n) (n=no. of nodes)

### HasPath

- An operation that returns that whether there exists a path from one node to another.
- Because in some graphs, there exists no path for some nodes.
- Both types of traversals can be used for this operation.

## Dijkstra Algorithm

- Shortest path problem
- Uses greedy approach
- Works on weighted graphs
- Problem :
    - Find shortest path to all the nodes from a source node.
- Weighted graphs have weights/cost to all edges.
- If there is not direct edge between two nodes, then the cost of the traversal is considered as infinity.
- If the cost to any node is updated to a better/lesser value, then it is called relaxation.
- Select the source node
- Calculate the weights to all the nodes
- Select the shortest path
- Perform relaxation
- Keep count of cost you have already paid, and add to it whenever you traverse.
- Update the source
- Repeat the steps until all nodes are visited.
- Time complexity : O(n^2) Worst Case 
- Doesnot consider negative weights
- Cannot work in this condition
- Gives the wrong results.

## Bellman Ford Algorithm

- Uses the dynamic programming approach
- First, mark a source node, and mark all costs of traversals as infinity
- Now perform relaxation to all the nodes.
- Do relaxation n-1 times, n being the no. of nodes.
- Time complexiy is O(n^2).
- For complete graph, time complexity is O(n^3)
- Can't work when there is a negative weigh cycle/loop in the graph.

## A* Algorithm

- Informed / heristic searching technique
- Used in AI
- Equation is : `f(N) = g(N) + h(N)`
- `g(N)` represents the actual cost from the start node to n
- `h(N)` represents the estimation cost from n to goal node.
- Estimated values can be calculated by breadth or depth first searches.

## Prim's Algorithm

- Problem is Minimum spanning tree.
- A spanning tree connects all n nodes, with only n-1 edges.
- No. of possible spanning trees = no. of edges C (combination) no. of vertices - 1 - no. of cycles.
- Finding the spanning tree with minimum cost is the problem we are solving.
- Prim's Algorithm 
- First, select the least cost edge.
- Then take the least cost edge from the two connected nodes.
- Always maintain a tree, don't take a far away node.
- Min spanning tree will be created.
- Time complexity O(n^2)

## Kruskal's Algorithm

- Min Spanning tree problem.
- Always select the least cost edge, you can take the distant edges/vertices too.
- vertices may or may not be connected.
- If any edge is forming a cycle, don't consider that edge.
- Time complexity O(n^2).
- can be optimized by using a min heap. takes O(n log n).
- For non connected graphs, kruskal's algo gives seperate results for both the graphs. but prim's algo gives result for only the 1st tree.
