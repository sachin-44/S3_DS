#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Function prototypes
void displayList(struct Node *head);
struct Node *insertAtBeginning(struct Node *head, int value);
struct Node *insertAtEnd(struct Node *head, int value);
struct Node *insertAtPosition(struct Node *head, int value, int position);
struct Node *deleteFromBeginning(struct Node *head);
struct Node *deleteFromEnd(struct Node *head);
struct Node *deleteFromPosition(struct Node *head, int position);

int main() {
    struct Node *head = NULL;
    int choice, value, position;

    do {
        printf("\nLinked List Operations:\n");
        printf("1. Display\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at a specified Position\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Delete from a specified Position\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayList(head);
                break;

            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                head = insertAtBeginning(head, value);
                displayList(head);
                break;

            case 3:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                head = insertAtEnd(head, value);
                displayList(head);
                break;

            case 4:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the position to insert at: ");
                scanf("%d", &position);
                head = insertAtPosition(head, value, position);
                displayList(head);
                break;

            case 5:
                head = deleteFromBeginning(head);
                displayList(head);
                break;

            case 6:
                head = deleteFromEnd(head);
                displayList(head);
                break;

            case 7:
                printf("Enter the position to delete from: ");
                scanf("%d", &position);
                head = deleteFromPosition(head, position);
                displayList(head);
                break;

            case 8:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 8);

    return 0;
}

void displayList(struct Node *head) {
    if (head == NULL) {
        printf("Linked List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

struct Node *insertAtBeginning(struct Node *head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

struct Node *insertAtEnd(struct Node *head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

struct Node *insertAtPosition(struct Node *head, int value, int position) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (position == 1) {
        newNode->next = head;
        return newNode;
    }

    struct Node *temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position. Insertion failed.\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

struct Node *deleteFromBeginning(struct Node *head) {
    if (head == NULL) {
        printf("Linked List is empty. Deletion failed.\n");
        return NULL;
    }

    struct Node *temp = head;
    head = head->next;
    free(temp);
    printf("Deleted element from the beginning.\n");
    return head;
}

struct Node *deleteFromEnd(struct Node *head) {
    if (head == NULL) {
        printf("Linked List is empty. Deletion failed.\n");
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node *temp = head;
    struct Node *prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
    printf("Deleted element from the end.\n");
    return head;
}

struct Node *deleteFromPosition(struct Node *head, int position) {
    if (head == NULL) {
        printf("Linked List is empty. Deletion failed.\n");
        return NULL;
    }

    if (position == 1) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        printf("Deleted element from position %d.\n", position);
        return head;
    }

    struct Node *temp = head;
    struct Node *prev = NULL;

    for (int i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position. Deletion failed.\n");
        return head;
    }

    prev->next = temp->next;
    free(temp);
    printf("Deleted element from position %d.\n", position);
    return head;
}
