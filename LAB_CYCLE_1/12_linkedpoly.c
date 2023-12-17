#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coefficient;
    int exponent;
    struct Node *next;
};

struct Node *createNode(int coefficient, int exponent);
struct Node *insertTerm(struct Node *head, int coefficient, int exponent);
void displayPolynomial(struct Node *head);
struct Node *multiplyPolynomials(struct Node *poly1, struct Node *poly2);
struct Node *addPolynomials(struct Node *poly1, struct Node *poly2);

int main() {
    struct Node *poly1 = NULL, *poly2 = NULL, *resultProduct = NULL, *resultSum = NULL;
    int coeff, exp, n;

    // Input for the first polynomial
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n);
    printf("Enter the terms (coefficient and exponent) for the first polynomial:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        poly1 = insertTerm(poly1, coeff, exp);
    }

    // Input for the second polynomial
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n);
    printf("Enter the terms (coefficient and exponent) for the second polynomial:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        poly2 = insertTerm(poly2, coeff, exp);
    }

    // Multiply polynomials and display result
    resultProduct = multiplyPolynomials(poly1, poly2);
    printf("\nProduct of the two polynomials:\n");
    displayPolynomial(resultProduct);

    // Add polynomials and display results
    resultSum = addPolynomials(poly1, poly2);
    printf("\nSum of the two polynomials:\n");
    printf("First Polynomial: ");
    displayPolynomial(poly1);
    printf("Second Polynomial: ");
    displayPolynomial(poly2);
    printf("Resultant Polynomial: ");
    displayPolynomial(resultSum);

    // Free memory
    free(poly1);
    free(poly2);
    free(resultProduct);
    free(resultSum);

    return 0;
}

struct Node *createNode(int coefficient, int exponent) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

struct Node *insertTerm(struct Node *head, int coefficient, int exponent) {
    struct Node *newNode = createNode(coefficient, exponent);

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

void displayPolynomial(struct Node *head) {
    if (head == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }

    while (head != NULL) {
        printf("%dx^%d", head->coefficient, head->exponent);
        head = head->next;

        if (head != NULL) {
            printf(" + ");
        }
    }

    printf("\n");
}

struct Node *multiplyPolynomials(struct Node *poly1, struct Node *poly2) {
    struct Node *result = NULL;

    while (poly1 != NULL) {
        struct Node *temp = poly2;
        while (temp != NULL) {
            int coeff = poly1->coefficient * temp->coefficient;
            int exp = poly1->exponent + temp->exponent;
            result = insertTerm(result, coeff, exp);
            temp = temp->next;
        }
        poly1 = poly1->next;
    }

    return result;
}

struct Node *addPolynomials(struct Node *poly1, struct Node *poly2) {
    struct Node *result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exponent > poly2->exponent) {
            result = insertTerm(result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            result = insertTerm(result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            int sum = poly1->coefficient + poly2->coefficient;
            result = insertTerm(result, sum, poly1->exponent);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    // Add remaining terms of poly1
    while (poly1 != NULL) {
        result = insertTerm(result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }

    // Add remaining terms of poly2
    while (poly2 != NULL) {
        result = insertTerm(result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }

    return result;
}
