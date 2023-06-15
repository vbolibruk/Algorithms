#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int queue[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initialize(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

bool is_empty(Queue* q) {
    return (q->front == -1 && q->rear == -1);
}

bool is_full(Queue* q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}

void enqueue(Queue* q, int item) {
    if (is_full(q)) {
        printf("Черга переповнена.\n");
        return;
    }

    if (is_empty(q))
        q->front = q->rear = 0;
    else
        q->rear = (q->rear + 1) % MAX_SIZE;

    q->queue[q->rear] = item;
}

int dequeue(Queue* q) {
    if (is_empty(q)) {
        printf("Черга порожня.\n");
        return -1;
    }

    int item = q->queue[q->front];

    if (q->front == q->rear)
        initialize(q);
    else
        q->front = (q->front + 1) % MAX_SIZE;

    return item;
}

int front(Queue* q) {
    if (is_empty(q)) {
        printf("Черга порожня.\n");
        return -1;
    }

    return q->queue[q->front];
}

int size(Queue* q) {
    if (is_empty(q))
        return 0;

    if (q->rear >= q->front)
        return q->rear - q->front + 1;
    else
        return MAX_SIZE - q->front + q->rear + 1;
}

int main() {
    Queue queue;
    initialize(&queue);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    printf("Розмір черги: %d\n", size(&queue));
    printf("Перший елемент черги: %d\n", front(&queue));

    int dequeued_item = dequeue(&queue);
    printf("Елемент, який вилучили з черги: %d\n", dequeued_item);

    printf("Чи черга порожня? %s\n", is_empty(&queue) ? "Так" : "Ні");

    return 0;
}
