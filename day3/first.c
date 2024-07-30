/* Question: Write a C program to compute the time taken in applying Merge sort algorithm on arrays of following
sizes: 50 elements, 100 elements, 500 elements, 2000 elements, 5000 elements.*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
int *arr;

void print(int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d  ", *(arr + i));
    }
    printf("\n");
}
void merge(int *arr, int a, int m, int b)
{
    int n1 = m - a + 1, n2 = b - m;
    int *temp1 = (int *)malloc(n1 * sizeof(int));
    int *temp2 = (int *)malloc(n2 * sizeof(int));
    int i = 0, j = 0, k = a;
    for (i = 0; i < n1; i++)
    {
        *(temp1 + i) = *(arr + a + i);
    }
    for (j = 0; j < n2; j++)
    {
        *(temp2 + j) = *(arr + m + 1 + j);
    }
    i = 0;
    j = 0;
    while (i < n1 && j < n2)
    {
        if (*(temp1 + i) <= *(temp2 + j))
        {
            *(arr + k) = *(temp1 + i);
            i++;
        }
        else
        {
            *(arr + k) = *(temp2 + j);
            j++;
        }
        k++;
    }
    if (i < n1)
    {
        while (i < n1)
        {
            *(arr + k) = *(temp1 + i);
            i++;
            k++;
        }
    }
    else if (j < n2)
    {
        while (j < n2)
        {
            *(arr + k) = *(temp2 + j);
            j++;
            k++;
        }
    }
    free(temp1);
    free(temp2);
}
void mergesort(int *arr, int a, int b)
{
    if (a >= b)
        return;
    int m = a + (b - a) / 2;
    mergesort(arr, a, m);
    mergesort(arr, m + 1, b);
    merge(arr, a, m, b);
}
void program()
{
    int n, i;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        *(arr + i) = rand() % 1000;
    }
    clock_t start = clock();
    mergesort(arr, 0, n - 1);
    clock_t stop = clock();
    double time = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("Time taken for merge sort: %lf\n", time);
    printf("Sorted Array:\n");
    print(arr, n);
    free(arr);
}
int main()
{
    int choice;
    do
    {
        printf("\n\n1.Run the program\n2.Exit the program\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            program();
            break;
        case 2:
            printf("Program Executed!!\n");
            break;
        default:
            printf("Invalid choice!!\n");
        }
    } while (choice != 2);

    return 0;
}