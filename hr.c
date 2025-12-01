#include <stdio.h>
#include <string.h>

#define MAX 100

struct Employee {
    int id;
    char name[50];
    char dept[20];
    float salary;
    int age;
};

struct Employee emp[MAX];
int count = 0;

// 1. Add Employee
void addEmployee() {
    printf("\nEnter ID: ");
    scanf("%d", &emp[count].id);
    printf("Enter Name: ");
    scanf("%s", emp[count].name);
    printf("Enter Department: ");
    scanf("%s", emp[count].dept);
    printf("Enter Salary: ");
    scanf("%f", &emp[count].salary);
    printf("Enter Age: ");
    scanf("%d", &emp[count].age);

    count++;
    printf("Employee Added Successfully!\n");
}

// 2. Display All Employees
void displayEmployees() {
    if(count == 0) {
        printf("\nNo Employees Found!\n");
        return;
    }
    printf("\n--- Employee Records ---\n");
    for(int i = 0; i < count; i++) {
        printf("\nID: %d\nName: %s\nDepartment: %s\nSalary: %.2f\nAge: %d\n",
            emp[i].id, emp[i].name, emp[i].dept, emp[i].salary, emp[i].age);
    }
}

// 3a. Search by ID
void searchByID() {
    int id;
    printf("\nEnter ID to Search: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++) {
        if(emp[i].id == id) {
            printf("\nRecord Found:\n");
            printf("ID: %d\nName: %s\nDepartment: %s\nSalary: %.2f\nAge: %d\n",
                emp[i].id, emp[i].name, emp[i].dept, emp[i].salary, emp[i].age);
            return;
        }
    }
    printf("Employee Not Found!\n");
}

// 4a. Average Salary Report
void averageSalary() {
    if(count == 0) {
        printf("\nNo Data Available!\n");
        return;
    }
    float total = 0;
    for(int i = 0; i < count; i++) {
        total += emp[i].salary;
    }
    printf("\nAverage Salary = %.2f\n", total / count);
}

// 4b. Highest Salary Report
void highestSalary() {
    if(count == 0) {
        printf("\nNo Data Available!\n");
        return;
    }

    float high = emp[0].salary;
    int index = 0;

    for(int i = 1; i < count; i++) {
        if(emp[i].salary > high) {
            high = emp[i].salary;
            index = i;
        }
    }

    printf("\n--- Highest Salary Employee ---\n");
    printf("Name: %s\nID: %d\nSalary: %.2f\n",
        emp[index].name, emp[index].id, emp[index].salary);
}

// 5a. Basic Salary Distribution (Simple count)
void salaryDistribution() {
    int low = 0, mid = 0, high = 0;

    for(int i = 0; i < count; i++) {
        if(emp[i].salary < 20000) low++;
        else if(emp[i].salary < 50000) mid++;
        else high++;
    }

    printf("\n--- Salary Distribution ---\n");
    printf("< 20,000 : %d employees\n", low);
    printf("20,000 - 50,000 : %d employees\n", mid);
    printf("> 50,000 : %d employees\n", high);
}

// 6. Update Employee
void updateEmployee() {
    int id;
    printf("\nEnter ID to Update: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++) {
        if(emp[i].id == id) {
            printf("Enter New Name: ");
            scanf("%s", emp[i].name);
            printf("Enter New Department: ");
            scanf("%s", emp[i].dept);
            printf("Enter New Salary: ");
            scanf("%f", &emp[i].salary);
            printf("Enter New Age: ");
            scanf("%d", &emp[i].age);

            printf("Record Updated Successfully!\n");
            return;
        }
    }
    printf("Employee Not Found!\n");
}

// 7. Delete Employee
void deleteEmployee() {
    int id;
    printf("\nEnter ID to Delete: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++) {
        if(emp[i].id == id) {
            for(int j = i; j < count - 1; j++) {
                emp[j] = emp[j + 1];
            }
            count--;
            printf("Employee Deleted Successfully!\n");
            return;
        }
    }
    printf("Employee Not Found!\n");
}

// MAIN MENU
int main() {
    int choice;

    while(1) {
        printf("\n============== HR REPORTS / ANALYTICS ==============\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3a. Search Employee by ID\n");
        printf("4a. Average Salary Report\n");
        printf("4b. Highest Salary Report\n");
        printf("5a. Salary Distribution\n");
        printf("6. Update Employee\n");
        printf("7. Delete Employee\n");
        printf("8. Exit\n");

        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchByID(); break;
            case 4: averageSalary(); break;
            case 5: salaryDistribution(); break;
            case 6: updateEmployee(); break;
            case 7: deleteEmployee(); break;
            case 8: return 0;
            default: printf("Invalid Choice!\n");
        }
    }

    return 0;
}
