/*Question: 3. Write a C program to compute the time taken to find the sum of elements in an array of following
sizes: 10 elements, 100 elements, 500 elements, 1000 elements, 2000 elements.*/

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
int calculate(int *arr, int n)
{
    int sum = 0, i;
    for (i = 0; i < n; i++)
    {
        sum += *(arr + i);
    }
    return sum;
}
void program()
{
    int n, i, sum;
    int *arr;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        *(arr + i) = rand() % 1000;
    }
    printf("Arary:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d  ", *(arr + i));
    }
    printf("\n\n");
    clock_t start, stop;
    float time;
    start = clock();
    sum = calculate(arr, n);
    stop = clock();
    time = (float)(stop - start) / CLOCKS_PER_SEC;
    printf("Sum: %d\n", sum);
    free(arr);
    printf("Time taken find the sum of %d elements: %f.\n", n, time);
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
