#include <stdio.h>
#include <stdlib.h>

struct QueueNode {
    int value;
    struct QueueNode* link;
};

struct QueueNode* frontPtr = NULL;
struct QueueNode* rearPtr = NULL;

int isQueueEmpty() {
    return (frontPtr == NULL);
}

void insertElement(int data) {
    struct QueueNode* newElement = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    
    if (newElement == NULL) {
        printf("Memory allocation unsuccessful! Cannot insert element.\n");
        return;
    }

    newElement->value = data;
    newElement->link = NULL;

    if (rearPtr == NULL) {
        frontPtr = rearPtr = newElement;
    } else {
        rearPtr->link = newElement;
        rearPtr = newElement;
    }

    printf("Inserted: %d\n", data);
}

void removeElement() {
    if (isQueueEmpty()) {
        printf("Queue is empty! No elements to remove.\n");
        return;
    }

    struct QueueNode* temp = frontPtr;
    printf("Removed: %d\n", temp->value);
    
    frontPtr = frontPtr->link;
    if (frontPtr == NULL) {
        rearPtr = NULL;
    }

    free(temp);
}

void getFront() {
    if (isQueueEmpty()) {
        printf("Queue is empty! No front element.\n");
        return;
    }
    printf("First element: %d\n", frontPtr->value);
}

void displayQueue() {
    if (isQueueEmpty()) {
        printf("Queue is currently empty!\n");
        return;
    }

    struct QueueNode* temp = frontPtr;
    printf("Current queue: ");
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->link;
    }
    printf("\n");
}

int main() {
    int option, data;
    
    while (1) {
        printf("\nQueue Menu:\n");
        printf("1. Insert\n");
        printf("2. Remove\n");
        printf("3. View Front\n");
        printf("4. Display Queue\n");
        printf("5. Check Empty\n");
        printf("6. Exit\n");
        printf("Select an option: ");

        if (scanf("%d", &option) != 1) {
            printf("Invalid input! Please enter a valid number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (option) {
            case 1:
                printf("Enter element to insert: ");
                if (scanf("%d", &data) != 1) {
                    printf("Invalid input! Please enter a number.\n");
                    while (getchar() != '\n');
                    continue;
                }
                insertElement(data);
                break;
            case 2:
                removeElement();
                break;
            case 3:
                getFront();
                break;
            case 4:
                displayQueue();
                break;
            case 5:
                printf(isQueueEmpty() ? "Queue is empty!\n" : "Queue has elements.\n");
                break;
            case 6:
                printf("Shutting down program...\n");
                return 0;
            default:
                printf("Invalid selection! Please choose a valid option.\n");
        }
    }
    return 0;
}
