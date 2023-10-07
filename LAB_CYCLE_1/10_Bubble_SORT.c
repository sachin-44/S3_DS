#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void bubble_sort(char arr[][MAX], int n) {
    char temp[MAX];
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }
}

int binary_search(char arr[][MAX], int n, char *key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (strcmp(arr[mid], key) == 0)
            return mid;
        else if (strcmp(arr[mid], key) < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return -1;
    }

    char arr[MAX][MAX];
    int n = 0;
    while (fgets(arr[n], MAX, fp)) {
        arr[n][strlen(arr[n]) - 1] = '\0';
        n++;
    }

    bubble_sort(arr, n);

    printf("Sorted strings:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }
//CSL201 DATA STRUCTURES LAB ----- DEION TOMSON
    char key[MAX];
    printf("\nEnter the string to search: ");
    scanf("%s", key);

    int index = binary_search(arr, n, key);
    if (index == -1)
        printf("String not found\n");
    else
        printf("String found at index %d\n", index);

    fclose(fp);

    return 0;
}
