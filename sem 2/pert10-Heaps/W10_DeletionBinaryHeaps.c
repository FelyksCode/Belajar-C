#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct MinHeap
{
    int *hArr;
    int capacity;
    int heapSize;
};

struct MinHeap createHeap(int cap)
{
    struct MinHeap newHeap;
    newHeap.heapSize = 0;
    newHeap.capacity = cap;
    newHeap.hArr = malloc(sizeof(int) * cap);

    int i;
    for (i = 0; i < cap; i++)
    {
        newHeap.hArr[i] = 0;
    }
    return newHeap;
}

int parent(int i)
{
    return (i - 1) / 2;
}

int left(int i)
{
    return (2 * i + 1);
}

int right(int i)
{
    return (2 * i + 2);
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void insertKey(struct MinHeap *mHeap, int k)
{
    printf("Current Heap Size = %d\n\n", mHeap->heapSize);
    printf("Inserting %d to Heap\n", k);
    if (mHeap->heapSize == mHeap->capacity)
    {
        printf("\nOverflow: Could not insertKey\n");
        return;
    }
    mHeap->heapSize++;
    int i = mHeap->heapSize - 1;
    mHeap->hArr[i] = k;

    while (i != 0 && mHeap->hArr[parent(i)] > mHeap->hArr[i])
    {
        swap(&mHeap->hArr[i], &mHeap->hArr[parent(i)]);
        i = parent(i);
    }
}

int getMin(struct MinHeap *mHeap)
{
    return mHeap->hArr[0];
}

void printHeap(struct MinHeap mHeap)
{
    printf("Current heap : ");
    for (int i = 0; i < mHeap.heapSize; i++)
    {
        printf("%d ", mHeap.hArr[i]);
    }
    printf("\n");
}

void MinHeapify(struct MinHeap *mHeap, int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < mHeap->heapSize && mHeap->hArr[i] < mHeap->hArr[i])
        smallest = l;
    if (r < mHeap->heapSize && mHeap->hArr[r] < mHeap->hArr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&mHeap->hArr[i], &mHeap->hArr[smallest]);
        MinHeapify(mHeap, smallest);
    }
}

int extractMin(struct MinHeap *mHeap)
{
    if (mHeap->heapSize <= 0)
        return INT_MAX;
    if (mHeap->heapSize == 1)
    {
        mHeap->heapSize--;
        return mHeap->hArr[0];
    }
    int root = mHeap->hArr[0];
    mHeap->hArr[0] = mHeap->hArr[mHeap->heapSize - 1];
    mHeap->heapSize--;
    MinHeapify(mHeap, 0);

    return root;
}

void decreaseKey(struct MinHeap *mHeap, int i, int newValue)
{
    mHeap->hArr[i] = newValue;
    while (i != 0 && mHeap->hArr[parent(i)] > mHeap->hArr[i])
    {
        swap(&mHeap->hArr[i], &mHeap->hArr[parent(i)]);
        i = parent(i);
    }
}

void deleteKey(struct MinHeap *mHeap, int i)
{
    printf("Current Heap Size = %d\n\n", mHeap->heapSize);
    printf("Deleting index %d from heap\n", i);
    decreaseKey(mHeap, i, INT_MIN);
    extractMin(mHeap);
}

int main()
{
    struct MinHeap mHeap;
    mHeap = createHeap(11);

    printHeap(mHeap);
    insertKey(&mHeap, 3);
    printHeap(mHeap);
    insertKey(&mHeap, 2);
    printHeap(mHeap);
    insertKey(&mHeap, 1);
    printHeap(mHeap);
    insertKey(&mHeap, 15);
    printHeap(mHeap);
    insertKey(&mHeap, 5);
    printHeap(mHeap);
    insertKey(&mHeap, 4);
    printHeap(mHeap);
    insertKey(&mHeap, 45);
    printHeap(mHeap);
    printf("Min Value in Heap: %d \n", getMin(&mHeap));

    extractMin(&mHeap);
    printHeap(mHeap);

    deleteKey(&mHeap, 1);
    printHeap(mHeap);

    return 0;
}