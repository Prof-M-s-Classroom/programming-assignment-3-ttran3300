#include "graph.h"
#include <climits>
#include <iostream>

#include "heap.h"
using namespace std;

Graph::Graph(int vertices) {
    numVertices = vertices;
    adjMatrix = new int*[vertices];
    for (int i = 0; i < vertices; i++) {
        adjMatrix[i] = new int[vertices];
        for (int j = 0; j < vertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}

Graph::~Graph() {
    for (int i = 0; i < numVertices; i++) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
}

void Graph::addEdge(int u, int v, int weight) {
    adjMatrix[u][v] = weight;
    adjMatrix[v][u] = weight;
}

void Graph::primMST() {
    int* parent = new int[numVertices];
    int*key = new int[numVertices];

    MinHeap heap(numVertices);

    for (int i = 0; i < numVertices; i++) {
        key[i] = INT_MAX;
        parent[i] = -1;
    }

    key[0] = 0;
    heap.decreaseKey(0,0);

    while (!heap.isEmpty()) {
        int u = heap.extractMin();

        for (int i = 0; i < numVertices; i++) {
            int weight = adjMatrix[u][i];
            if (weight && heap.isInMinHeap(i) && weight < key[i]) {
                key[i] = weight;
                parent[i] = u;
                heap.decreaseKey(i, weight);
            }
        }
    }

    int totalWeight = 0;

    for (int i = 1; i < numVertices; i++) {
        cout << parent[i] << "--" << i << " : " << adjMatrix[i][parent[i]] << " (Edge Weight)" << endl;
        totalWeight += adjMatrix[i][parent[i]];
    }

    cout<<"Total Weight of MST: "<<totalWeight<<endl;

    delete[] key;
    delete[] parent;

}

