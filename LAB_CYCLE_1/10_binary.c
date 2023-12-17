#include <stdio.h>
#include <string.h>

void bubbleSort(char arr[][100], int n) {
for (int i = 0; i < n - 1; ++i) {
for (int j = 0; j < n - i - 1; ++j) {
if (strcmp(arr[j], arr[j + 1]) > 0) {
char temp[100];
strcpy(temp, arr[j]);
strcpy(arr[j], arr[j + 1]);
strcpy(arr[j + 1], temp);
}
}
}
}

int binarySearch(char arr[][100], int n, const char* key) {
int low = 0, high = n - 1;
while (low <= high) {
int mid = (low + high) / 2;
int cmp = strcmp(arr[mid], key);
if (cmp == 0) {
return mid;
} else if (cmp < 0) {
low = mid + 1;
} else {
high = mid - 1;
}
}
return -1;
}
int main() {
FILE* file = fopen("input.txt", "r");
if (!file) {
printf("Error opening file.\n");
return 1;

}
char strings[100][100];
int count = 0;

while (fscanf(file, "%s", strings[count]) != EOF) {
count++;
}
fclose(file);

bubbleSort(strings, count);
printf("Sorted strings:\n");
for (int i = 0; i < count; ++i) {
printf("%s\n", strings[i]);
}

char searchKey[100];
printf("Enter a string to search: ");
scanf("%s", searchKey);
int result = binarySearch(strings, count, searchKey);
if (result != -1) {
printf("Found at index %d.\n", result);
} else {
printf("Not found.\n");
}
return 0;
}
