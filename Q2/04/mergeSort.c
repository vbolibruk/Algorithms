// Illustrate the operation of merge sort on an array
// initially containing the sequence <3, 41, 52, 26, 38, 57, 9, 49>
// Реалізуйте алгоритм Merge Sort
// Реалізуйте ітеративний варіант алгоритму Merge Sort (додаткові бали)

// <3, 41, 52, 26, 38, 57, 9, 49>
// <3, 41, 52, 26> <38, 57, 9, 49>
// <3, 41> <52, 26> <38, 57> <9, 49>
// <3> <41> <52> <26> <38> <57> <9> 49>
// <3, 41>  <26 ,52> <38, 57> <9, 49>
// <3,26, 41,52> <9,38,49,57>
// <3, 9 26 38 41 49 52 57>

#include <stdio.h>
#include <stdlib.h>

#define N 8

void Merge(int A[], int p, int q, int r)
{
    int i, j, k, n_L, n_R;
    int *L, *R;

    n_L = q - p + 1;
    n_R = r - q;

    L = (int *)malloc(n_L * sizeof(int));
    R = (int *)malloc(n_R * sizeof(int));

    for (i = 0; i < n_L - 1; i++)
        L[i] = A[p + i];

    for (i = 0; i < n_R - 1; i++)
        R[i] = A[p + i];

    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = p; // Initial index of merged subarray

    while (i < n_L && j < n_R)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n_L)
    {
        A[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n_R)
    {
        A[k] = R[j];
        j++;
        k++;
    }

    //
    //
    //

    free(L);
    free(R);
}

void MergeSort(int A[], int p, int r)
{
    if (r < p)
    {
        int mid = p + (r - p) / 2;
        MergeSort(A, p, mid);
        MergeSort(A, mid + 1, r);
        Merge(A, p, mid, r);
    }
}

void PrintArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
            printf("%s\n", "");

}

int main(void)
{
    int X[N] = {3, 41, 52, 26, 38, 57, 9, 49};

    PrintArray(X, N);
    MergeSort(X, 0, N);
    PrintArray(X, N);

    return 0;
}
