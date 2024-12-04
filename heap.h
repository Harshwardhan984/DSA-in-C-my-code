// heap.h

typedef struct {
    int size;
    int *data;
} Heap;

void heapify(Heap *heap, int n, int i);
void heapSort(Heap *heap);


