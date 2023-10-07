// Code starts
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int EmpId;
    char Name[100];
    float Salary;
};

void linearSearch(struct Employee *emp, int n, int id) {
    int i;
    for (i = 0; i < n; i++) {
        if (emp[i].EmpId == id) {
            printf("Employee found at index %d\n", i);
            printf("EmpId: %d\n", emp[i].EmpId);
            printf("Name: %s\n", emp[i].Name);
            printf("Salary: %.2f\n", emp[i].Salary);
            return;
        }
    }//CSL201 DATA STRUCTURES LAB ----- DEION TOMSON
    printf("Employee not found\n");
}

int main() {
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    struct Employee *emp = (struct Employee *)malloc(n * sizeof(struct Employee));

    for (int i = 0; i < n; i++) {
        printf("Enter details of employee %d:\n", i + 1);
        printf("EmpId: ");
        scanf("%d", &emp[i].EmpId);
        printf("First Name: ");
        scanf("%s", emp[i].Name);
        printf("Middle Name: ");
        scanf("%s", emp[i].Name + strlen(emp[i].Name));
        printf("Last Name: ");
        scanf("%s", emp[i].Name + strlen(emp[i].Name));
        printf("Salary: ");
        scanf("%f", &emp[i].Salary);
    }

    int id;
    printf("\nEnter EmpId to search: ");
    scanf("%d", &id);

    linearSearch(emp, n, id);

    free(emp);

    return 0;
}
