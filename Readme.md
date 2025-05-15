[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/K_t6ffJX)
# Prim's Algorithm with Min Heap and Adjacency Matrix

## Author
Tammy Tran

## Description
Briefly describe what your program does and how the code is structured.
In this program, I worked to implement Prim's algorithm to find the Minimum Spanning Tree (MST) that is weighted and undirected graph. 
The code is organized into two separate components to a structure. 
The graph.h/graph.cpp represent the graph that uses adjacency matrix and contains implementations of Prim's algorithms. These files contain methods like primMST() that helps create the MST and addEdge() to build the graph.
The files heap.h/heap.cpp contain methods like insertKey(), decreaseKey(), and extractMin() to help correctly structure and define a min heap. These are important because it efficiently and accurately selects the next vertex with the minimum key.

## Files
- graph.h / graph.cpp
- heap.h / heap.cpp
- main.cpp (unchanged)
- README.md

## How to Compile and Run
This project was developed and tested in CLion.  
Run directly from the IDE.

## Time Complexity Analysis


| Operation            | Time Complexity |
|----------------------|-----------------|
| Insert in MinHeap    | O(logn)         |
| Extract Min          | O(logn)         |
| Decrease Key         | O(logn)         |
| Prim’s MST Overall   | O(n^2)          |

_Explain why your MST implementation has the above runtime._
Insert in MinHeap - This has a runtime of O(logn) because when a new vertex is added to the heap, it may need to swap with its parent node to maintain heap property. In the worse case, it can take logn steps.
Extract Min - This has a runtime of O(logn) because it removes the smallest key and can cause the heap to be restructured. In the worse case, it can take logn steps.
Decrease Key - This has a runtime of O(logn) because, like insert in MinHeap, the updated vertex may need to swap which takes logn in the worst case.
Prim’s MST Overall - Since the graph uses adjacency matrix, the overall time is O(n^2). This is because it checks all n vertices to find the minimum key.

## Test Case Description

Input:  
#include <iostream>
#include "graph.h"

int main() {
Graph g(5);
g.addEdge(0, 1, 2);
g.addEdge(0, 3, 6);
g.addEdge(1, 2, 3);
g.addEdge(1, 3, 8);
g.addEdge(1, 4, 5);
g.addEdge(2, 4, 7);
g.addEdge(3, 4, 9);

    g.primMST();

    return 0;
}

Output:
0--1 : 2 (Edge Weight)
1--2 : 3 (Edge Weight)
0--3 : 6 (Edge Weight)
1--4 : 5 (Edge Weight)
Total Weight of MST: 16

Process finished with exit code 0

## Assumptions

I made the assumption that all th edge weights were non-negative numbers.
