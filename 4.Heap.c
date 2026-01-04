#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int sizeMax = 0;
int sizeMin = 0;

void insertMax(int heap[], int value) {
    int i = sizeMax++;
    heap[i] = value;

    while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

void deleteMax(int heap[]) {
    if (sizeMax == 0) 
	return;

    heap[0] = heap[--sizeMax];

    int i = 0;
    while (1) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < sizeMax && heap[left] > heap[largest])
            largest = left;
        if (right < sizeMax && heap[right] > heap[largest])
            largest = right;

        if (largest == i) break;

        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        i = largest;
    }
}


void insertMin(int heap[], int value) {
    int i = sizeMin++;
    heap[i] = value;

    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

void deleteMin(int heap[]) {
    if (sizeMin == 0) return;

    heap[0] = heap[--sizeMin];

    int i = 0;
    while (1) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < sizeMin && heap[left] < heap[smallest])
            smallest = left;
        if (right < sizeMin && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == i) break;

        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        i = smallest;
    }
}

void printHeap(int heap[], int size) {
	int i;
    for ( i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    int maxHeap[MAX], minHeap[MAX];
    int n, x;
	int i;
    printf("Kac eleman girilecek: ");
    scanf("%d", &n);

    printf("Elemanlari girin:\n");
    for ( i = 0; i < n; i++) {
        scanf("%d", &x);
        insertMax(maxHeap, x);
        insertMin(minHeap, x);
    }

    printf("\nMax Heap: ");
    printHeap(maxHeap, sizeMax);

    printf("Min Heap: ");
    printHeap(minHeap, sizeMin);

    deleteMax(maxHeap);
    deleteMin(minHeap);

    printf("\nMax Heap (delete root): ");
    printHeap(maxHeap, sizeMax);

    printf("Min Heap (delete root): ");
    printHeap(minHeap, sizeMin);

    return 0;
}

