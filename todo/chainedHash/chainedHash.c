#include <stdio.h>
#include <stdlib.h>                     // malloc(), free()

#define  NIL  NULL
#define  m    11

struct object {
   int key;
   struct  object *next;
};

typedef struct object obj;

obj *T[m] = {NIL};                   // each hash-table slot T[j] contains a
                                     // linked list of all the keys whose hash value is j

int h(int);
obj *Create_Object(int);
void Chained_Hash_Insert(obj *);
obj *Chained_Hash_Search(int);
void Chained_Hash_Delete(int);
void Chained_Hash_Print_Table(void);


int main(void) {
    obj *p;
    int i;

    for (i = 0; i < m; i++)             // initialize hash table
        T[i] = NIL;

    p = Create_Object(10); Chained_Hash_Insert(p);  // Exercises 11.4-1
    p = Create_Object(22); Chained_Hash_Insert(p);
    p = Create_Object(31); Chained_Hash_Insert(p);
    p = Create_Object( 4); Chained_Hash_Insert(p);
    p = Create_Object(15); Chained_Hash_Insert(p);
    p = Create_Object(28); Chained_Hash_Insert(p);
    p = Create_Object(17); Chained_Hash_Insert(p);
    p = Create_Object(88); Chained_Hash_Insert(p);
    p = Create_Object(59); Chained_Hash_Insert(p);
    Chained_Hash_Print_Table();

    p = Chained_Hash_Search(15);
    if (p != NIL)
        printf("Element with this key %d found!\n", p -> key);
    else
        printf("Key not found!\n");

    Chained_Hash_Delete(15);
    Chained_Hash_Delete(22);
    Chained_Hash_Print_Table();
    Chained_Hash_Delete(59);
    Chained_Hash_Print_Table();
    Chained_Hash_Delete(28);
    Chained_Hash_Print_Table();

   return 0;
}


// hash function (division method)
int h(int k) {
   return k % m;
}


obj *Create_Object(int k) {
   obj *p;

   p = (obj *)malloc(sizeof(obj));
   p->key = k;

   return p;
}


// insert x at the head of list T[ h(x->key) ]
void Chained_Hash_Insert(obj *x) {
   int j = h(x->key);

   x->next = T[j];
   T[j]    = x;
}


// search for an element with key k in the list T[ h(k) ]
obj *Chained_Hash_Search(int k) {
    obj *head;

    head = T[h(k)];
    while (head != NIL && head -> key != k)
        head = head -> next;
    
    return head;
}


// delete x from the list T[ h(x->key) ]
// void Chained_Hash_Delete(int k) {
//     obj *head, *prev;

//     // ???
// }

// delete x from the list T[ h(x->key) ]
void Chained_Hash_Delete(int k) {
    int j = h(k);
    obj *head = T[j];
    obj *prev = NULL;

    while (head != NIL && head->key != k) {
        prev = head;
        head = head->next;
    }

    if (head == NIL) {
        printf("Key not found!\n");
        return;
    }

    if (prev == NULL) {
        // Видаляємо перший вузол списку
        T[j] = head->next;
    } else {
        // Видаляємо вузол з середини або кінця списку
        // 1 2 3 
        prev->next = head->next;
    }

    free(head);
}

// print hash table
void Chained_Hash_Print_Table(void) {
    int j;
    obj *head;

    for (j = 0; j < m; j++) {
        printf("T[%2i]", j);
        head = T[j];
        while (head != NIL) {
            printf(" ->%3i", head -> key);
            head = head -> next;
        }
        printf("\n");
    }
    printf("\n");
}
