#include "heap.h"
#include <climits>
#include <iostream>
using namespace std;

MinHeap::MinHeap(int capacity) {
    size = 0;

    heapArray = new int[capacity];
    keyArray = new int[capacity];
    position = new int[capacity];

    for (int i = 0; i < capacity; i++) {
        keyArray[i] = INT_MAX;
        position[i] = i;
        heapArray[i] = i;
    }
    size = capacity;
}

MinHeap::~MinHeap() {   //destructor to clean memory
    delete[] heapArray;
    delete[] position;
    delete[] keyArray;
}

void MinHeap::insert(int vertex, int key) {     //add vertex and key into the heap
    if (size == capacity) {                     //checks for space
        cout << "Heap full.. cannot insert." << endl;
        return;
    }

    int i = size;                               //adds vertex to the end and updates array
    heapArray[i] = vertex;
    keyArray[i] = key;
    position[vertex] = i;
    size++;

    while (i != 0 && keyArray[heapArray[i]] < keyArray[heapArray[(i - 1) / 2]]) { //ensures it is at correct spot
        int parent = (i - 1) / 2;

        int temp = heapArray[i];                //swaps vertex w parent
        heapArray[i] = heapArray[parent];
        heapArray[parent] = temp;

        position[heapArray[i]] = i;             //updates position
        position[heapArray[parent]] = parent;

        i = parent;
    }
}

void MinHeap::minHeapify(int idx) {
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    int smallest = idx;

    if (left < size && keyArray[heapArray[left]] < keyArray[heapArray[smallest]]) {
        smallest = left;
    }

    if (right < size && keyArray[heapArray[right]] < keyArray[heapArray[smallest]]) {
        smallest = right;
    }

    if (smallest != idx) {
        swap(heapArray[idx], heapArray[smallest]);
        position[heapArray[idx]] = idx;
        position[heapArray[smallest]] = smallest;

        minHeapify(smallest);
    }
}

int MinHeap::extractMin() {
    if (isEmpty()) {
        cout << "Heap is empty." << endl;
        return -1;
    }

    int root = heapArray[0];
    heapArray[0] = heapArray[size-1];

    position[heapArray[0]] = 0;
    position[root] = size-1;

    size--;
    minHeapify(0);

    return root;
}

void MinHeap::decreaseKey(int vertex, int newKey) {
    keyArray[vertex] = newKey;
    int i = position[vertex];

    while (i > 0 && keyArray[heapArray[i]] < keyArray[heapArray[(i - 1) / 2]]) {
        swap(heapArray[i], heapArray[(i - 1) / 2]);
        swap(position[heapArray[i]], position[heapArray[(i - 1) / 2]]);
        i = (i - 1) / 2;
    }
}

bool MinHeap::isInMinHeap(int vertex) {
    return position[vertex] < size;
}

bool MinHeap::isEmpty() {
    return size == 0;
}