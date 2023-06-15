#include <stdio.h>

// Оголошення структури
struct Person {
    char name[50];
    int age;
};

int main() {
    // Оголошення структурної змінної
    struct Person person;

    // Оголошення вказівника на структуру
    struct Person* ptr = &person;

    // Заповнення полів структури через вказівник
    printf("Введіть ім'я: ");
    scanf("%s", ptr->name);
    printf("Введіть вік: ");
    scanf("%d", &(ptr->age));

    // Виведення даних про особу
    printf("Ім'я: %s\n", ptr->name);
    printf("Вік: %d\n", ptr->age);

    return 0;
}
