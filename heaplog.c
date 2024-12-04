// prologic.c
#include <stdio.h>
#include "heap.h"

// Heapify a subtree with root at index i in the Heap struct
void heapify(Heap *heap, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // If left child is larger than root
    if (left < n && heap->data[left] > heap->data[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && heap->data[right] > heap->data[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        int temp = heap->data[i];
        heap->data[i] = heap->data[largest];
        heap->data[largest] = temp;

        // Recursively heapify the affected sub-tree
        heapify(heap, n, largest);
    }
}

// Function to perform heap sort using the Heap struct
void heapSort(Heap *heap) {
    int n = heap->size;

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(heap, n, i);

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        int temp = heap->data[0];
        heap->data[0] = heap->data[i];
        heap->data[i] = temp;

        // Call max heapify on the reduced heap
        heapify(heap, i, 0);
    }
}

