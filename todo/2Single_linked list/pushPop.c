#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

// Ініціалізація стеку
void initializeStack(struct Stack* stack) {
    stack->top = NULL;
}

// Перевірка, чи є стек порожнім
int isEmpty(struct Stack* stack) {
    return (stack->top == NULL);
}

// Додавання елементу до стеку (Push)
void push(struct Stack* stack, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Видалення елементу зі стеку (Pop)
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Стек порожній!\n");
        return -1; // Повертаємо -1 як помилку
    }

    struct Node* temp = stack->top;
    int poppedData = temp->data;
    stack->top = temp->next;
    free(temp);
    return poppedData;
}

// Отримання верхнього елементу стеку без видалення (Top)
int top(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Стек порожній!\n");
        return -1; // Повертаємо -1 як помилку
    }

    return stack->top->data;
}

// Друкування стеку
void printStack(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Стек порожній!\n");
        return;
    }

    struct Node* current = stack->top;
    printf("Стек: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    initializeStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printStack(&stack); // Виведе: Стек: 30 20 10

    printf("Верхній елемент: %d\n", top(&stack)); // Виведе: Верхній елемент: 30

    int poppedElement = pop(&stack);
    printf("Видалений елемент: %d\n", poppedElement); // Виведе: Видалений елемент: 30

    printStack(&stack); // Виведе: Стек: 20 10

    return 0;
}
