#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    char ssn[15];
    char name[20];
    char dept[5];
    char designation[10];
    int salary;
    long long int phno;
    struct Employee *next;
};

typedef struct Employee Employee;

Employee *head = NULL;
Employee *tail = NULL;

Employee* createEmployee(char ssn[], char name[], char dept[], char designation[], int salary, long long int phno) {
    Employee *emp = (Employee *)malloc(sizeof(Employee));
    if (emp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    strcpy(emp->ssn, ssn);
    strcpy(emp->name, name);
    strcpy(emp->dept, dept);
    strcpy(emp->designation, designation);
    emp->salary = salary;
    emp->phno = phno;
    emp->next = NULL;
    return emp;
}

void insertAtBeginning(Employee *emp) {
    emp->next = head;
    head = emp;
    if (tail == NULL) {
        tail = emp;
    }
}

void insertAtEnd(Employee *emp) {
    if (tail == NULL) {
        head = emp;
        tail = emp;
    } else {
        tail->next = emp;
        tail = emp;
    }
}

void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Employee *temp = head;
    head = head->next;
    free(temp);
    if (head == NULL) {
        tail = NULL;
    }
}

void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Employee *temp = head;
    Employee *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    if (prev != NULL) {
        prev->next = NULL;
        tail = prev;
    } else {
        head = NULL;
        tail = NULL;
    }

    free(temp);
}

void display() {
    Employee *temp = head;
    printf("Employee Details:\n");
    while (temp != NULL) {
        printf("%s\n%s\n%s\n%s\n%d\n%lld\n\n", temp->ssn, temp->name, temp->dept, temp->designation, temp->salary, temp->phno);
        temp = temp->next;
    }
}

int main() {
    int choice;
    char ssn[15], name[20], dept[5], designation[10];
    int salary;
    long long int phno;

    printf("1. Create\n2. Display\n3. Insert at beginning\n4. Insert at End\n5. Delete at beginning\n6. Delete at End\n7. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the required data (Emp no, Name, Dept, Desig, sal, phone): ");
                scanf("%s%s%s%s%d%lld", ssn, name, dept, designation, &salary, &phno);
                insertAtEnd(createEmployee(ssn, name, dept, designation, salary, phno));
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Enter the required data (Emp no, Name, Dept, Desig, sal, phone): ");
                scanf("%s%s%s%s%d%lld", ssn, name, dept, designation, &salary, &phno);
                insertAtBeginning(createEmployee(ssn, name, dept, designation, salary, phno));
                break;
            case 4:
                printf("Enter the required data (Emp no, Name, Dept, Desig, sal, phone): ");
                scanf("%s%s%s%s%d%lld", ssn, name, dept, designation, &salary, &phno);
                insertAtEnd(createEmployee(ssn, name, dept, designation, salary, phno));
                break;
            case 5:
                deleteFromBeginning();
                break;
            case 6:
                deleteFromEnd();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
