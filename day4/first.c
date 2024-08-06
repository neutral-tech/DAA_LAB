/* Question: Write a C program to compute the time taken in applying insertion sort algorithm on arrays of following
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
void insertionsort(int *arr, int n)
{
    int i = 0, temp, j;
    for (i = 1; i < n; i++)
    {
        temp = *(arr + i);
        j = i - 1;
        while (j >= 0 && *(arr + j) > temp)
        {
            *(arr + j + 1) = *(arr + j);
            j--;
        }
        *(arr + j + 1) = temp;
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
    insertionsort(arr, n);
    clock_t stop = clock();
    double time = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("Time taken for insertion sort: %lf\n", time);
    // printf("Sorted Array:\n");
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