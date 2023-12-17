#include <stdio.h>
#include <stdlib.h>

// Node structure for a queue element
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function prototypes
struct Queue* createQueue();
void enqueue(struct Queue* queue, int value);
void dequeue(struct Queue* queue);
void displayQueue(struct Queue* queue);

int main() {
    struct Queue* queue = createQueue();
    int choice, value;

    do {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &value);
                enqueue(queue, value);
                displayQueue(queue);
                break;

            case 2:
                dequeue(queue);
                displayQueue(queue);
                break;

            case 3:
                displayQueue(queue);
                break;

            case 4:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    // Free memory before exiting
    while (queue->front != NULL) {
        struct Node* temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
    }

    free(queue);

    return 0;
}

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (!queue) {
        printf("Memory allocation error. Unable to create queue.\n");
        exit(EXIT_FAILURE);
    }

    queue->front = NULL;
    queue->rear = NULL;

    return queue;
}

// Function to enqueue an element into the queue
void enqueue(struct Queue* queue, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation error. Unable to enqueue element.\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = value;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    printf("Element %d enqueued into the queue.\n", value);
}

// Function to dequeue an element from the queue
void dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue underflow. Cannot dequeue element.\n");
        return;
    }

    struct Node* temp = queue->front;
    queue->front = queue->front->next;

    // If the queue becomes empty after dequeue
    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    int dequeuedValue = temp->data;
    free(temp);

    printf("Dequeued element: %d\n", dequeuedValue);
}

// Function to display the elements of the queue
void displayQueue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");
    struct Node* temp = queue->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
