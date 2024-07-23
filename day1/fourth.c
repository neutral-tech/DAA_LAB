/*Question: 4. Write a C program to compute the time taken to find the minimum number in an array of following
sizes: 10 elements, 100 elements, 500 elements, 1000 elements, 2000 elements. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
int main()
{
   int choice;
   clock_t start, stop;
   float time;
   int *arr;
   int n, i, min = INT_MAX;
   do
   {
      min = INT_MAX;
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
            *(arr + i) = rand() % 1000;
         }
         start = clock();
         for (i = 0; i < n; i++)
         {
            if (*(arr + i) < min)
               min = *(arr + i);
         }
         stop = clock();
         time = (float)(stop - start) / CLOCKS_PER_SEC;
         printf("Minimum element in the array is %d.\n", min);
         printf("Time taken for binary search: %f.\n", time);
         break;
      case 2:
         printf("Program Executed.\n");
         break;
      default:
         printf("Invalid Input!!!\n");
      }
   } while (choice != 2);
}
