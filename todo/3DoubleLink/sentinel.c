#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void printList(struct Node* head) {
    struct Node* current = head->next; // Починаємо з першого вузла після sentinel-вартового

    while (current != head) { // Продовжуємо, поки не досягнемо повторно sentinel-вартового
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void insertAtBeginning(struct Node* head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;

    // Змінюємо посилання наступного вузла нового вузла і вузла після sentinel-вартового
    newNode->next = head->next;
    newNode->next->prev = newNode;

    // Змінюємо посилання попереднього вузла нового вузла і sentinel-вартового
    newNode->prev = head;
    head->next = newNode;
}

void insertAtEnd(struct Node* head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;

    struct Node* current = head;

    // Знаходимо останній вузол
    while (current->next != head) {
        current = current->next;
    }

    // Змінюємо посилання наступного вузла останнього вузла і sentinel-вартового
    newNode->next = head;
    current->next = newNode;

    // Змінюємо посилання попереднього вузла останнього вузла і нового вузла
    newNode->prev = current;
    head->prev = newNode;
}

void deleteNode(struct Node* head, int key) {
    struct Node* current = head->next;

    // Шукаємо вузол з ключем, який треба видалити
    while (current != head && current->data != key) {
        current = current->next;
    }

    if (current == head) {
        printf("Element not found in the list\n");
        return;
    }

    // Змінюємо посилання попереднього вузла наступного вузла вузла, який треба видалити
    current->prev->next = current->next;
    current->next->prev = current->prev;

    free(current); // Видаляємо вузол
}

int main() {
    // Створюємо sentinel-вартовий вузол
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = -1;
    head->prev = head;
    head->next = head;

    insertAtBeginning(head, 1);
    insertAtBeginning(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);

    printf("List: ");
    printList(head);

    deleteNode(head, 2);

    printf("List after deletion: ");
    printList(head);

    free(head); // Видаляємо sentinel-вартовий вузол

    return 0;
}
