#include <stdio.h>
#include <stdlib.h>

// Вузол черги
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Черга
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Створення нового вузла з заданим значенням
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Створення порожньої черги
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Перевірка, чи є черга порожньою
int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

// Додавання елемента до кінця черги
void enqueue(Queue* queue, int data) {
    Node* newNode = createNode(data);

    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        newNode->prev = queue->rear;
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Видалення першого елемента з черги
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Помилка: черга порожня!\n");
        return -1;
    }

    Node* removedNode = queue->front;
    int removedData = removedNode->data;

    if (queue->front == queue->rear) {
        // Черга містить тільки один елемент
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        queue->front = queue->front->next;
        queue->front->prev = NULL;
    }

    free(removedNode);
    return removedData;
}

// Виведення елементів черги
void printQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Черга порожня!\n");
        return;
    }

    Node* current = queue->front;
    printf("Елементи черги: ");

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

// Очищення пам'яті, виділеної для черги
void freeQueue(Queue* queue) {
    Node* current = queue->front;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    free(queue);
}

int main() {
    Queue* queue = createQueue();

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    printf("Елементи черги: ");
    printQueue(queue);

    int dequeuedData = dequeue(queue);
    printf("Видалений елемент: %d\n", dequeuedData);

    printf("Елементи черги після видалення: ");
    printQueue(queue);

    freeQueue(queue);
    return 0;
}
