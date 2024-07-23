/*Question: 1. Write a C program to compute the time taken to apply bubble sort on an array of following sizes:
10 elements, 100 elements, 500 elements, 1000 elements, 2000 elements.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *arr, int i, int j)
{
    int temp = *(arr + i);
    *(arr + i) = *(arr + j);
    *(arr + j) = temp;
    return;
}
void bubbleSort(int *arr, int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (*(arr + j) > *(arr + j + 1))
            {
                swap(arr, j, j + 1);
            }
        }
    }
    return;
}
void program()
{
    int n, i;
    int *arr;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        *(arr + i) = rand() % 1000;
    }
    printf("Unsorted arary:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d  ", *(arr + i));
    }
    printf("\n\n");
    clock_t start, stop;
    float time;
    start = clock();
    bubbleSort(arr, n);
    stop = clock();
    time = (float)(stop - start) / CLOCKS_PER_SEC;
    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d  ", *(arr + i));
    }
    printf("\n\n");
    free(arr);
    printf("Time taken for applying bubble sort in array of %d elements: %f.\n", n, time);
}
int main()
{
    int choice;
    do
    {
        printf("\n1.Run the program\n2.Exit the program\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            program();
            break;
        case 2:
            printf("Program executed!!\n");
            break;
        default:
            printf("Invalid choice!!\n");
        }
    } while (choice != 2);
    return 0;
}
