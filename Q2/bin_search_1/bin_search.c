#include <stdio.h>
#include <stdlib.h>                     // malloc(), free()

#define  NIL  NULL

struct tree_node {
   int key;
   struct tree_node *p;
   struct tree_node *left;
   struct tree_node *right;   
};

typedef struct tree_node tnode;

tnode *root = NIL;


void InorderTreeWalk(tnode *x) {
    if (x != NIL) {
        InorderTreeWalk(x->left);
        printf("%3d", x->key);
        InorderTreeWalk(x->right);
    }
}


void PreorderTreeWalk(tnode *x) {
    if (x != NIL) {
        printf("%3d", x->key);
        InorderTreeWalk(x->left);
        InorderTreeWalk(x->right);
        
    }
}


void PostorderTreeWalk(tnode *x) {
    if (x != NIL) {
        InorderTreeWalk(x->left);
        InorderTreeWalk(x->right);
        printf("%3d", x->key);

    }
}


tnode *TreeSearchRecursive(tnode *x, int k) {
    if (x == NIL || k == x->key)
        return x;
    else if (k < x->key)
        return TreeSearchRecursive(x->left, k);
    else
        return TreeSearchRecursive(x->right, k);
}


tnode *TreeSearchIterative(tnode *x, int k) {
    while (x != NIL && k != x->key)
        if (k < x->key)
            x = x->left;
        else
            x = x->right;
    return x;
}


tnode *TreeMinimumIterative(tnode *x) {
    while (x->left != NIL)
        x = x->left;
    
    return x;
}


tnode *TreeMinimumRecursive(tnode *x) {
    if (x == NULL) {
        return NULL;  // Дерево пустое
    } else if (x->left == NULL) {
        return x;  // Найден узел с минимальным значением ключа
    } else {
        return TreeMinimumRecursive(root->left);  // Рекурсивно ищем в левом поддереве
    }
}


tnode *TreeMaximumIterative(tnode *x) {
    while (x->right != NIL)
        x = x->right;
    return x;
}


tnode *TreeMaximumRecursive(tnode *x) {
    if (x == NULL) {
        return NULL;  // Дерево пустое
    } else if (x->right == NULL) {
        return x;  // Найден узел с минимальным значением ключа
    } else {
        return TreeMaximumRecursive(root->right);  // Рекурсивно ищем в левом поддереве
    }
}

// without pointer to parent 
tnode *create_tnode(int k, tnode *left_child, tnode *right_child) {
    tnode *x;
    
    x = (tnode *)malloc(sizeof(tnode));

    x->p     = NIL;
    x->key   = k;
    x->left  = left_child;
    x->right = right_child;
    
    return x;
}


void BuildTree(void) {
/*
                        6
                       / \
                      /   \
                     5     7
                    / \     \
                   2   5     8                     
*/
    root = create_tnode(
        6,
        create_tnode(
            5,
            create_tnode(2, NIL, NIL),
            create_tnode(5, NIL, NIL)
        ),
        create_tnode(
            7,
            NIL,
            create_tnode(8, NIL, NIL)
        )
    );
}

int main(void) {
    tnode *p;
    
    BuildTree();
    
    InorderTreeWalk(root);      printf("\n");
    //PreorderTreeWalk(root);     printf("\n");
    //PostorderTreeWalk(root);    printf("\n");
    
    p = TreeSearchRecursive(root, 8);
    if (p != NIL)
        printf("Element with this key %i found!\n", p->key);
    else
        printf("Key not found!\n");
    p = TreeSearchRecursive(root, 10);
    if (p != NIL)
        printf("Element with this key %i found!\n", p->key);
    else
        printf("Key not found!\n");

    p = TreeMinimumIterative(root);
    printf("The minimum element is %i\n", p->key);
    //p = TreeMinimumRecursive(root);
    //printf("The minimum element is %i\n", p->key);

    p = TreeMaximumIterative(root);
    printf("The maximum element is %i\n", p->key);
    //p = TreeMaximumRecursive(root);
    //printf("The maximum element is %i\n", p->key);

    return 0;
}
