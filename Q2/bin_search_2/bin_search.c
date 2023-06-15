#include <stdio.h>
#include <stdlib.h> // malloc(), free()

#define NIL NULL

struct tree_node
{
    int key;
    struct tree_node *p;
    struct tree_node *left;
    struct tree_node *right;
};

typedef struct tree_node tnode;

tnode *root = NIL;
tnode *root2 = NIL;

void InorderTreeWalk(tnode *x)
{
    if (x != NIL)
    {
        InorderTreeWalk(x->left);
        printf("%3d", x->key);
        InorderTreeWalk(x->right);
    }
}

void PreorderTreeWalk(tnode *x)
{
    if (x != NIL)
    {
        printf("%3d", x->key);
        PreorderTreeWalk(x->left);
        PreorderTreeWalk(x->right);
    }
}

void PostorderTreeWalk(tnode *x)
{
    if (x != NIL)
    {
        PostorderTreeWalk(x->left);
        PostorderTreeWalk(x->right);
        printf("%3d", x->key);
    }
}

tnode *TreeSearchRecursive(tnode *x, int k)
{
    if (x == NIL || k == x->key)
        return x;
    else if (k < x->key)
        return TreeSearchRecursive(x->left, k);
    else
        return TreeSearchRecursive(x->right, k);
}

tnode *TreeSearchIterative(tnode *x, int k)
{
    while (x != NIL && k != x->key)
        if (k < x->key)
            x = x->left;
        else
            x = x->right;
    return x;
}

tnode *TreeMinimumIterative(tnode *x)
{
    while (x->left != NIL)
        x = x->left;

    return x;
}

tnode *TreeMinimumRecursive(tnode *x)
{
    if (x == NULL)
    {
        return NULL; // Дерево пустое
    }
    else if (x->left == NULL)
    {
        return x; // Найден узел с минимальным значением ключа
    }
    else
    {
        return TreeMinimumRecursive(root->left); // Рекурсивно ищем в левом поддереве
    }
}

tnode *TreeMaximumIterative(tnode *x)
{
    while (x->right != NIL)
        x = x->right;
    return x;
}

tnode *TreeMaximumRecursive(tnode *x)
{
    if (x == NULL)
    {
        return NULL; // Дерево пустое
    }
    else if (x->right == NULL)
    {
        return x; // Найден узел с минимальным значением ключа
    }
    else
    {
        return TreeMaximumRecursive(root->right); // Рекурсивно ищем в левом поддереве
    }
}

// without pointer to parent
tnode *create_tnode(int k, tnode *left_child, tnode *right_child)
{
    tnode *x;

    x = (tnode *)malloc(sizeof(tnode));

    x->p = NIL;
    x->key = k;
    x->left = left_child;
    x->right = right_child;

    return x;
}

void BuildTree(void)
{
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
            create_tnode(5, NIL, NIL)),
        create_tnode(
            7,
            NIL,
            create_tnode(8, NIL, NIL)));
}
tnode *TreeInsert(tnode *root, int key)
{
    tnode *newNode = create_tnode(key, NULL, NULL);
    if (root == NULL)
    {
        // Дерево пустое, создаем новый узел
        
        return newNode;
    }

    if (key < root->key)
    {
        // Вставляем в левое поддерево
        if (root->left == NULL)
        {
            root->left = newNode;
        }
        else
        {
            root->left = TreeInsert(root->left, key);
        }
    }
    else if (key > root->key)
    {
        // Вставляем в правое поддерево

        if (root->right == NULL)
        {
            root->right = newNode;
        }
        else
        {
            root->right = TreeInsert(root->right, key);
        }
    }

    return root;
}

int main(void)
{
    tnode *p;

    BuildTree();
    // root2 = create_tnode(20, NIL, NIL);
    TreeInsert(root,20);
    InorderTreeWalk(root);
    printf("\n");
    // PreorderTreeWalk(root);     printf("\n");
    // PostorderTreeWalk(root);    printf("\n");

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
    // p = TreeMinimumRecursive(root);
    // printf("The minimum element is %i\n", p->key);

    p = TreeMaximumIterative(root);
    printf("The maximum element is %i\n", p->key);
    // p = TreeMaximumRecursive(root);
    // printf("The maximum element is %i\n", p->key);

    return 0;
}

// находит узел с наименьшим ключом, большим заданного ключа
tnode *TreeSuccessor(tnode *node)
{
    if (node->right != NULL)
    {
        return TreeMinimumIterative(node->right); // Преемник находится в правом поддереве
    }

    tnode *parent = node->p;
    while (parent != NULL && node == parent->right)
    {
        node = parent;
        parent = parent->p;
    }

    return parent; // Преемник находится в родительском узле или отсутствует
}

// находит узел с наибольшим ключом, меньшим заданного ключа
tnode *TreePredecessor(tnode *node)
{
    if (node->left != NULL)
    {
        return TreeMaximumIterative(node->left); // Предшественник находится в левом поддереве
    }

    tnode *parent = node->p;
    while (parent != NULL && node == parent->left)
    {
        node = parent;
        parent = parent->p;
    }

    return parent; // Предшественник находится в родительском узле или отсутствует
}

void Transplant(tnode** root, tnode* u, tnode* v) {
    if (u->p == NULL) {
        // Замена корня дерева
        *root = v;
    } else if (u == u->p->left) {
        // Замена левого поддерева
        u->p->left = v;
    } else {
        // Замена правого поддерева
        u->p->right = v;
    }
    
    if (v != NULL) {
        v->p = u->p;  // Обновление родительского указателя
    }
}


void deleteTree(struct tree_node* tnode)
{
    if (tnode == NULL) return;
 
    /* first delete both subtrees */
    deleteTree(tnode->left);
    deleteTree(tnode->right);
   
    /* then delete the node */
    printf("\n Deleting node: %d", tnode->key);
    free(tnode);
}
 
