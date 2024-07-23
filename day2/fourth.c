/*Question: sizes: 4. Write a C program to compute the time taken to find the difference between sum of all odd
numbers and sum of all even numbers present in an array of following sizes: 10 elements, 100
elements, 500 elements, 1000 elements, 2000 elements.*/

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
    int odd = 0, even = 0, i = 0;
    for (i = 0; i < n; i++)
    {
        if ((*(arr + i) % 2) == 0)
            even += *(arr + i);
        else
            odd += *(arr + i);
    }
    return odd - even;
}
void program()
{
    int n, i, result;
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
    result = calculate(arr, n);
    stop = clock();
    time = (float)(stop - start) / CLOCKS_PER_SEC;
    free(arr);
    printf("Difference between sum of all odd elements and sum of all even elements: %d\n", result);
    printf("Time taken find the difference between sum of all odd elements and sum of all even elements: %f.\n", time);
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
