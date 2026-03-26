#include <stdio.h>
int heap[100];
int size = 0;
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void insert(int val) {
    size++;
    int i = size;
    heap[i] = val;
    while (i > 1 && heap[i/2] > heap[i]) {
        swap(&heap[i], &heap[i / 2]);
        i = i / 2;
    }
}
int deleteMin() {
    int min = heap[1];
    heap[1] = heap[size];
    size--;
    int i = 1, child;
    while (i * 2 <= size) {
        child = i * 2;
        if (child + 1 <= size && heap[child + 1] < heap[child])
            child++;
        if (heap[i] <= heap[child])
            break;
        swap(&heap[i], &heap[child]);
        i = child;
    }
    return min;
}
void display() {
	int i;
    for ( i = 1; i <= size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}
int main() {
    insert(30);
    insert(10);
    insert(20);
    insert(5);

    printf("Min Heap: ");
    display();

    printf("Deleted minimum element: %d\n", deleteMin());

    printf("Min Heap after deletion: ");
    display();

    return 0;
}
