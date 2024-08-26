/*1. Write a C program to compute the time taken in applying Heap sort algorithm on arrays of
following sizes: 50 elements, 100 elements, 500 elements, 2000 elements, 5000 elements.*/
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
    *(arr + i) = *(arr + i) ^ *(arr + j);
    *(arr + j) = *(arr + i) ^ *(arr + j);
    *(arr + i) = *(arr + i) ^ *(arr + j);
    return;
}
void heapify(int *arr, int n)
{
    int i = 0, j = 0;
    for (i = 0; i < n; i++)
    {
        j = i;
        while (j > 0)
        {
            if (*(arr + j) > *(arr + (j / 2)))
            {
                swap(arr, j, j / 2);
            }
            else
                break;
            j /= 2;
        }
    }
    return;
}
int findmax(int *arr, int i, int j)
{
    if (*(arr + i) > *(arr + j))
        return i;
    return j;
}
void heapsort(int *arr, int n)
{
    int i, left, right, largest;
    while (n > 1)
    {
        swap(arr, 0, n - 1);
        n--;
        i = 0;
        while (1)
        {
            left = 2 * i + 1;
            right = 2 * i + 2;
            if (left >= n)
                break;
            else if (right >= n)
                largest = left;
            else
                largest = findmax(arr, left, right);
            if (*(arr + i) < *(arr + largest))
            {
                swap(arr, i, largest);
                i = largest;
            }
            else
                break;
        }
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
    // printf("Input array:\n");
    // print(arr, n);
    clock_t start = clock();
    heapify(arr, n);
    // printf("Heap:\n");
    // print(arr, n);
    heapsort(arr, n);
    clock_t stop = clock();
    double time = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("Time taken for heap sort: %lf\n", time);
    // printf("Sorted array:\n");
    // print(arr, n);
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
