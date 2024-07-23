/*Question:1. Write a C program to compute the time taken
  to apply linear search on an array of following sizes: 10 elements
  ,100 elements, 500 elements, 1000 elements, 2000 elements. (element to be
  searched should be the last element of the array)*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int choice;
  clock_t start, stop;
  float time;
  int *arr;
  int n, i, temp;
  do
  {
    printf("\n1.Run the program\n2.Exit the program\n\nEnter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("Enter the length of the array: ");
      scanf("%d", &n);
      arr = (int *)malloc(n * sizeof(int));
      for (i = 0; i < n; i++)
      {
        *(arr + i) = rand() % 10000;
      }
      // Linear search
      temp = arr[n - 1];
      start = clock();
      for (i = 0; i < n; i++)
      {
        if (*(arr + i) == temp)
        {
          printf("Element found at index %d.\n", i);
        }
      }
      stop = clock();
      time = (float)(stop - start) / CLOCKS_PER_SEC;
      printf("Time taken for linear search: %f.\n", time);
      break;
    case 2:
      printf("Program Executed.\n");
      break;
    default:
      printf("Invalid Input!!!\n");
    }
  } while (choice != 2);
}
