#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int stack[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack* s) {
    s->top = -1;
}

bool is_empty(Stack* s) {
    return s->top == -1;
}

bool is_full(Stack* s) {
    return s->top == MAX_SIZE - 1;
}

void push(Stack* s, int item) {
    if (is_full(s)) {
        printf("Стек переповнений.\n");
        return;
    }
    s->stack[++(s->top)] = item;
}

int pop(Stack* s) {
    if (is_empty(s)) {
        printf("Стек порожній.\n");
        return -1;
    }
    return s->stack[(s->top)--];
}

int peek(Stack* s) {
    if (is_empty(s)) {
        printf("Стек порожній.\n");
        return -1;
    }
    return s->stack[s->top];
}

int size(Stack* s) {
    return s->top + 1;
}

int main() {
    Stack stack;
    initialize(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    printf("Розмір стеку: %d\n", size(&stack));
    printf("Верхній елемент стеку: %d\n", peek(&stack));

    int popped_item = pop(&stack);
    printf("Елемент, який вилучили зі стеку: %d\n", popped_item);

    printf("Чи стек порожній? %s\n", is_empty(&stack) ? "Так" : "Ні");

    return 0;
}
