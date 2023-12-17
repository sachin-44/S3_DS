#include <stdio.h>
#include <stdlib.h>

// Node structure for a stack element
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
void push(struct Node** top, int value);
void pop(struct Node** top);
void displayStack(struct Node* top);

int main() {
    struct Node* top = NULL;
    int choice, value;

    do {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &value);
                push(&top, value);
                displayStack(top);
                break;

            case 2:
                pop(&top);
                displayStack(top);
                break;

            case 3:
                displayStack(top);
                break;

            case 4:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    // Free memory before exiting
    while (top != NULL) {
        struct Node* temp = top;
        top = top->next;
        free(temp);
    }

    return 0;
}

// Function to push an element onto the stack
void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation error. Unable to push element.\n");
        return;
    }

    newNode->data = value;
    newNode->next = *top;
    *top = newNode;

    printf("Element %d pushed onto the stack.\n", value);
}

// Function to pop an element from the stack
void pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack underflow. Cannot pop element.\n");
        return;
    }

    struct Node* temp = *top;
    *top = (*top)->next;
    int poppedValue = temp->data;
    free(temp);

    printf("Popped element: %d\n", poppedValue);
}

// Function to display the elements of the stack
void displayStack(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack: ");
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}
