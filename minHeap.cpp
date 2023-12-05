//Prahalad Gururajan
//CPSC 2120 Section 007
//November 27, 2023
//Min-Heap Implementation Using a Vector

/*Description: This code is a Min-Heap implemantation using a vector. A min-heap is a tree-based data
structure where each node has a lesser or equal value to all its children nodes. To do this, the code 
has implementations of the insert() and removeMin() functions which maintain the heap property with the 
private helper functions siftUp() and siftDown(). Additionally there is a parameterized constructor that 
takes a vector; this function is implemented to build the heap from the bottom-up (insert() should not be called). */

#include "minHeap.h"
#include <iostream>  

using namespace std;

// Private helper function to maintain the heap property by moving a node up
void minHeap::siftUp(int pos) {
    while (pos > 0) {
        int parent = (pos - 1) / 2;
        if (heap[pos] < heap[parent]) {
            swap(heap[pos], heap[parent]);
            pos = parent;
        } else {
            break;
        }
    }
}

// Private helper function to maintain the heap property by moving a node down
void minHeap::siftDown(int pos) {
    int size = heap.size();
    while (2 * pos + 1 < size) {
        int leftChild = 2 * pos + 1;
        int rightChild = 2 * pos + 2;
        int minChild = leftChild;

        if (rightChild < size && heap[rightChild] < heap[leftChild]) {
            minChild = rightChild;
        }

        if (heap[pos] > heap[minChild]) {
            swap(heap[pos], heap[minChild]);
            pos = minChild;
        } else {
            break;
        }
    }
}

// Parameterized constructor to build the heap from bottom-up
minHeap::minHeap(vector<int> data) : heap(data) {
    int size = heap.size();
    for (int i = size / 2 - 1; i >= 0; i--) {
        siftDown(i);
    }
}

// Insert a value into the heap
void minHeap::insert(int value) {
    heap.push_back(value);
    siftUp(heap.size() - 1);
}

// Remove the minimum value from the heap
int minHeap::removeMin() {
    if (heap.empty()) {
        cerr << "Heap is empty. Cannot remove the minimum element." << endl;
        return -1; // Or throw an exception
    }

    int minVal = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    siftDown(0);
    return minVal;
}