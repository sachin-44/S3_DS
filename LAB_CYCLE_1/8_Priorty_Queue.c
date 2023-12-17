#include <stdio.h>

#define MAX_SIZE 10

// Function prototypes
void insertElement(int element, int priority);
void deleteElement();
void displayQueue();

// Global variables
int priorityQueue[MAX_SIZE];
int front = -1, rear = -1;

int main() {
    int choice, element, priority;

    do {
        printf("\nPriority Queue Operations:\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the priority of the element: ");
                scanf("%d", &priority);
                insertElement(element, priority);
                displayQueue();
                break;

            case 2:
                deleteElement();
                displayQueue();
                break;

            case 3:
                displayQueue();
                break;

            case 4:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

void insertElement(int element, int priority) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue overflow. Cannot insert element.\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
        priorityQueue[rear] = element;
    } else {
        int i;
        for (i = rear; i >= front && priority < priorityQueue[i]; i--) {
            priorityQueue[i + 1] = priorityQueue[i];
        }
        priorityQueue[i + 1] = element;
        rear++;
    }

   //printf("Element %d with priority %d inserted successfully.\n", element, priority);
}

void deleteElement() {
    if (front == -1) {
        printf("Queue underflow. Cannot delete element.\n");
        return;
    }

    printf("Deleted element: %d\n", priorityQueue[front]);

    if (front == rear) {
        // Only one element in the queue
        front = rear = -1;
    } else {
        front++;
    }
}

void displayQueue() {
    if (front == -1) {
        printf("Priority Queue is empty.\n");
        return;
    }

    printf("Priority Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", priorityQueue[i]);
    }
    printf("\n");
}
