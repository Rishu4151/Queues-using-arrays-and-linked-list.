#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 10  
void insert(int item);
void removeElement();
void frontElement();
void showQueue();
int isQueueEmpty();
int isQueueFull();
int queue[CAPACITY], frontPos = -1, rearPos = -1;

int isQueueEmpty() 
{
    return (frontPos == -1);
}
int isQueueFull() 
{
    return (rearPos == CAPACITY - 1);
}
void insert(int item) 
{
    if (isQueueFull()) 
    {
        printf("Queue overflow! Cannot insert %d.\n", item);
        return;
    }
    if (isQueueEmpty()) 
    {
        frontPos = 0;
    }
    queue[++rearPos] = item;
    printf("Inserted: %d\n", item);
    showQueue();
}
void removeElement() 
{
    if (isQueueEmpty()) 
    {
        printf("Queue underflow! Cannot remove an element.\n");
        return;
    }
    printf("Removed: %d\n", queue[frontPos]);
    if (frontPos == rearPos) 
    {
        frontPos = rearPos = -1;
    } else {
        frontPos++;
    }
    showQueue();
}
void frontElement() 
{
    if (isQueueEmpty()) 
    {
        printf("Queue is empty! No front element.\n");
        return;
    }
    printf("First element: %d\n", queue[frontPos]);
}
void showQueue() 
{
    if (isQueueEmpty()) 
    {
        printf("Queue is currently empty!\n");
        return;
    }
    printf("Queue contents: ");
    for (int i = frontPos; i <= rearPos; i++) 
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}
int main() 
{
    int option, value;
    while (1) 
    {
        printf("\nQueue Menu:\n");
        printf("1. Insert\n");
        printf("2. Remove\n");
        printf("3. View Front\n");
        printf("4. Show Queue\n");
        printf("5. Check Empty\n");
        printf("6. Check Full\n");
        printf("7. Exit\n");
        printf("Select an option: ");

        if (scanf("%d", &option) != 1) 
        {
            printf("Invalid input! Enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (option) 
        {
            case 1:
                printf("Enter value to insert: ");
                if (scanf("%d", &value) != 1) 
                {
                    printf("Invalid input! Enter a number.\n");
                    while (getchar() != '\n');
                    continue;
                }
                insert(value);
                break;
            case 2:
                removeElement();
                break;
            case 3:
                frontElement();
                break;
            case 4:
                showQueue();
                break;
            case 5:
                printf(isQueueEmpty() ? "Queue is empty!\n" : "Queue contains elements.\n");
                break;
            case 6:
                printf(isQueueFull() ? "Queue is full!\n" : "Queue has available space.\n");
                break;
            case 7:
                printf("Closing program...\n");
                exit(0);
            default:
                printf("Invalid selection! Try again.\n");
        }
    }
    return 0;
}
