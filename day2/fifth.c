/*Question: 5. Write a C program to create a Student linked list containing roll numbers of the students. Compute
the time taken to traverse through the linked list of different sizes.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct student student;
struct student
{
    int roll;
    student *next;
};
student *head = NULL, *last = NULL;
void insert()
{
    student *newnode = (student *)malloc(sizeof(student));
    newnode->roll = rand() % 100000;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
        last = head;
        return;
    }
    else
    {
        last->next = newnode;
        last = newnode;
    }
}
void create()
{
    int n, i = 0;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        insert();
}
void traverse()
{
    if (head == NULL)
    {
        printf("NO DATA!!\n");
        return;
    }
    student *temp = head;
    int i = 1;
    printf("List of roll numbers of students:\n");
    while (temp != NULL)
    {
        printf("%d. %d\n", i, temp->roll);
        temp = temp->next;
        i++;
    }
    printf("\n\n");
}
void program()
{
    clock_t start, stop;
    float time;
    create();
    start = clock();
    traverse();
    stop = clock();
    time = (float)(stop - start) / CLOCKS_PER_SEC;
    printf("Time taken to traverse: %f.\n", time);
    head = NULL;
    last = NULL;
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
