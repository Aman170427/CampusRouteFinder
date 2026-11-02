# Campus Route Finder Using Graphs

## 1. Project Overview
Campus Route Finder is a C++ application that represents campus locations as vertices and paths between them as edges. It helps users explore campus locations and find the shortest route between two connected locations.

## 2. Technologies Used
- Programming Language: C++
- Concepts: Graphs, BFS, DFS, Queue, Adjacency List
- IDE: Dev-C++

## 3. Campus Locations
The project contains nine locations:
1. Main Gate
2. Library
3. Block 1
4. Block 2
5. Cafeteria
6. Auditorium
7. Parking
8. Lab
9. Sports Ground

## 4. Features
- Displays all campus locations.
- Represents the graph using an adjacency list.
- Uses Breadth-First Search (BFS) to find the shortest route in an unweighted graph.
- Uses Depth-First Search (DFS) to display reachable locations.
- Identifies disconnected locations.
- Provides a menu-driven interface.

## 5. Algorithms Used

### Breadth-First Search (BFS)
BFS explores vertices level by level using a queue. It finds a route with the minimum number of edges in an unweighted graph.

### Depth-First Search (DFS)
DFS explores a path as deeply as possible before backtracking. It is used to find reachable locations.

## 6. Time and Space Complexity

For an adjacency-list graph:

- BFS Time Complexity: O(V + E)
- DFS Time Complexity: O(V + E)
- Graph Storage Space: O(V + E)
- Auxiliary Space for BFS/DFS: O(V)

Here, V represents the number of vertices and E represents the number of edges.

## 7. Test Cases

| Test Case | Input | Expected Result |
|---|---|---|
| Direct Route | Main Gate to Library | Route found with 1 edge |
| Multi-Stop Route | Main Gate to Parking | Shortest route found with 4 edges |
| Unreachable Destination | Main Gate to Lab | No route exists |

## 8. How to Run
1. Open main.cpp in Dev-C++.
2. Compile and run the program.
3. Select an option from the menu.
4. Enter valid location numbers when prompted.

## 9. Conclusion
The project demonstrates graph representation, BFS-based shortest-route finding, DFS traversal, and reachability analysis using C++.