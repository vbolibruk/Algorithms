// linked list function:
// List_Insert()
// List_Search()
// List_Delete()
// List_Print()

#include <stdio.h>
#include <stdlib.h>

struct OBJECT {
    int key;
    struct OBJECT *next;
};
typedef struct OBJECT obj;

obj *head = NULL;  // linked list is empty

void List_Print(void){
    obj *p;
    
    printf("head ");
    p = head;
    while (p != NULL) {
        printf("--> %i ", p->key);
        p = p->next; // step to next element
    }
    printf("\n");
}

obj *List_Search(int k) {
    obj *p;

    p = head;
    while (p != NULL && p->key != k)
        p = p->next; 
        
    return p;
}

void List_Insert(int k) {
    obj *p;
    
    p = (obj *)malloc( sizeof(obj) );   // malloc - Memory ALLOCation
    p->key = k;                         // (*p).key = k;
    p->next = head;
    head = p;
}

void List_InsertAfter(obj* afterNode, int k) {
    if (afterNode == NULL) {
        printf("Попередній вузол не може бути NULL!\n");
        return;
    }

    obj* newNode = (obj*)malloc(sizeof(obj));
    newNode->key = k;
    newNode->next = afterNode->next;
    newNode->prev = afterNode;
    afterNode->next = newNode;


    newNode->next = nextNode->next;
    nextNode->next = newNode;

}

void List_Insert(Node* prevNode, Node* newNode) {
    if (prevNode == NULL) {
        // Если prevNode равен NULL, вставка невозможна
        printf("Ошибка: Неверный узел для вставки.\n");
        return;
    }

    newNode->next = prevNode->next;
    newNode->prev = prevNode;
    
    if (prevNode->next != NULL) {
        prevNode->next->prev = newNode;
    }
    prevNode->next = newNode;
}


void List_Delete(obj *p) {
    obj *prev;
    
    // If will I delete first element into linked list?
    // If will I delete last element into linked list?
    
    // found prev
    prev = head;
    while (prev->next != p)
        prev = prev->next;
    
    // change link
    prev->next = p->next;
    
    // free memory
    free(p);
}


void List_Delete(obj *p) {
    // If p is the first element
    if (p == head) {
        head = p->next;
    } else {
        obj *prev = head;

        // Find the previous node
        while (prev->next != p) {
            prev = prev->next;
        }

        // Change the link
        prev->next = p->next;
    }

    // Free memory
    free(p);
}

int main(void) {
    obj *p; 

    // 9, 16, 4, 1
    // head -> 9 -> 16 -> 4 -> 1 -> NULL
    //            key  next         key  next         key  next       key  next
    //           ---------         ---------         ---------        ----------
    // head---->|  9  |  -|-----> | 16 |   -|------>|  4  |  -|----->|  1 | NULL|
    //           ---------         ---------         ---------        ----------
    List_Insert(1);  // List_Print();
    List_Insert(4);  // List_Print();
    List_Insert(16); // List_Print();
    List_Insert(9);
    List_Print();
    
    List_Insert(25); // linked list: head -> 25 -> 9 -> 16 -> 4 -> 1 -> NULL
    List_Print();
    
    p = List_Search(4);
    if (p != NULL)
        printf("Found element %i\n", p->key);
    else
        printf("Element not found!\n");
    
    p = List_Search(5);
    if (p != NULL)
        printf("Found element %i\n", p->key);
    else
        printf("Element not found!\n");
    
    // delete '4'
    p = List_Search(4);
    if (p != NULL) {
        List_Delete(p);
        List_Print();  // linked list: head -> 25 -> 9 -> 16 -> 1 -> NULL
    }
    
    // delete '1'
    p = List_Search(1);
    if (p != NULL) {
        List_Delete(p);
        List_Print();  // linked list: head -> 25 -> 9 -> 16 -> NULL
    }

    // delete '25'
    p = List_Search(25);
    if (p != NULL) {
        List_Delete(p);
        List_Print();  // linked list: head -> 9 -> 16 -> NULL
    }

    return 0;
}
