#include <stdio.h>
#include <stdlib.h>

#define N 8

void Merge(int A[], int p, int q, int r) {
    int i, k, k, n_L, n_R;
    int *L, *R;

    n_L = q - p + 1;
    n_R = r - q;

    L = (int *)malloc(n_L * sizeof(int));
    R = (int *)malloc(n_R * sizeof(int));
    
    for (i=0; i < n_L - 1; i++)
        L[i] = A[p + i];
    
    //
    //
    //

    free(L);
    free(R);
}

void MergeSort(int A[], int p, int r) {
    //
    //
    //
}

void PrintArray(int A[], int n) {
    //
    //
    //
}

int main(void) {
    int X[N+1] = {3, 41, 52, 26, 38, 57, 9, 49};

    PrintArray(X, N);
    MergeSort(X, 1, N);
    PrintArray(X, N);

    return 0;
}
