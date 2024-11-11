#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

struct Queue {
    int front;
    int rear;
    int count;
    int data[MAX_QUEUE_SIZE];
};

void initialize(struct Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

int is_empty(struct Queue *q) {
    return q->count == 0;
}

int is_full(struct Queue *q) {
    return q->count == MAX_QUEUE_SIZE;
}

void enqueue(struct Queue *q, int num) {
    if (is_full(q)) {
        printf("Queue is full, cannot enqueue.\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = num;
    q->count++;
}

int dequeue(struct Queue *q, int num) {
    if (is_empty(q)) {
        printf("Queue is empty, cannot dequeue.\n");
        return -1;
    }
    int dequeued = q->data[q->front];
    if (num > dequeued) {
        printf("Dequeueing %d elements from the front.\n", q->count);
        initialize(q);
        enqueue(q, num);
    } else {
        printf("Enqueueing %d elements at the rear.\n", dequeued);
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
        q->count--;
        enqueue(q, dequeued);
    }
    return dequeued;
}

int main() {
    struct Queue q;
    initialize(&q);
    int num;
    while (1) {
        printf("Input a number: ");
        scanf("%d", &num);
        if (is_empty(&q)) {
            printf("Queue is empty, enqueueing %d elements.\n", num);
            for (int i = 0; i < num; i++) {
                enqueue(&q, num);
            }
        } else {
            dequeue(&q, num);
        }
    }
    return 0;
}
