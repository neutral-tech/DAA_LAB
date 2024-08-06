/* Question: Write a C program to compute the time taken in applying quick sort algorithm on arrays of following
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
void swap(int *arr, int i, int j)
{
    int temp = *(arr + i);
    *(arr + i) = *(arr + j);
    *(arr + j) = temp;
}
int partition(int *arr, int low, int high)
{
    int pivot = *(arr + high);
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (*(arr + j) < pivot)
        {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high);
    return (i + 1);
}

void quicksort(int *arr, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
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
    quicksort(arr, 0, n - 1);
    clock_t stop = clock();
    double time = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("Time taken for quick sort: %lf\n", time);
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