# ShortPathsBFS
C++ program that uses an adjacency list to represent an unweighted graph and applies BFS (Breadth-First Search) using a queue to find the shortest path from a starting node to all other nodes:

# Graph Representation:
  - The graph is represented using an adjacency list. Each node has a list of its adjacent nodes. This is stored as an array of lists where each index corresponds to a node, and the list contains its neighbors.

## BFS Algorithm:
  - The BFS algorithm starts from a given source node (`src`).
  - It uses a queue to explore nodes level by level, ensuring that each node's shortest path from the source is discovered first.
  - A distance vector `dist[]` is maintained to track the shortest distance from the source node to every other node. Initially, all distances are set to `INT_MAX` (infinity), except the source, which has a distance of `0`.
    Each time an adjacent node is found that hasn't been visited (i.e., still has a distance of `INT_MAX`), the distance is updated and the node is added to the queue for further exploration.

## Example:
In the provided example graph with 6 nodes and the following edges:
```
0 - 1, 0 - 3, 1 - 2, 3 - 4, 4 - 5, 2 - 5
```
The BFS is run from node 0, and the shortest distance to each node is calculated.
### Sample Output:
```
Shortest distances from node 0 to all other nodes:
Node 0 : 0
Node 1 : 1
Node 2 : 2
Node 3 : 1
Node 4 : 2
Node 5 : 3
```
This output shows the shortest path distances from node 0 to all other nodes. For example, node 1 is at distance 1 from node 0, node 5 is at distance 3, and so on.

## Time Complexity:
  - BFS Time Complexity: O(V + E), where V is the number of vertices, and E is the number of edges. Each vertex is processed once, and each edge is considered twice (since it's an undirected graph).
