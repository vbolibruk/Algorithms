#include <stdio.h>
#include <stdlib.h>

// Структура для вузла списку
struct Node {
    int data;
    struct Node* next;
};

// Функція для додавання нового вузла в кінець списку
void addNode(struct Node** head, int value) {
    // Створення нового вузла
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // Якщо список порожній, встановлюємо новий вузол як голову списку
    if (*head == NULL) {
        *head = newNode;
    }
    // Інакше, переходимо до кінця списку і додаємо новий вузол
    else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Функція для виведення елементів списку
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Додавання елементів до списку
    addNode(&head, 9);
    addNode(&head, 16);
    addNode(&head, 4);
    addNode(&head, 1);

    // Виведення списку
    printf("Елементи списку: ");
    printList(head);

    return 0;
}
