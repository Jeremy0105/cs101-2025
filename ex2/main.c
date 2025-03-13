#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int   id;
    char  name[20];
    int   age;
    float salary;
} employee_t;

void emp_info(employee_t emp[], int n);
void emp_writefile(employee_t emp[], int n, const char *filename);
void emp_readfile(employee_t emp[], int n, const char *filename);

int main(void) {
    employee_t emp[3];

    emp_info(emp, 3);

    emp_writefile(emp, 3, "employee.bin");

    memset(emp, 0, sizeof(emp));

    emp_readfile(emp, 3, "employee.bin");

    for(int i = 0; i < 3; i++) {
        printf("[%d] %d %s\n", i, emp[i].id, emp[i].name);
    }
    printf("\n");

    for(int i = 0; i < 3; i++) {
        printf("employee id = %d\n", emp[i].id);
        printf("employee name = %s\n", emp[i].name);
        printf("employee age = %d\n", emp[i].age);
        printf("employee salary = %f\n", emp[i].salary);
        printf("\n");
    }

    return 0;
}


void emp_info(employee_t emp[], int n) {
    emp[0].id = 1;
    strcpy(emp[0].name, "IU");
    emp[0].age = 20;
    emp[0].salary = 30000.0f;

    emp[1].id = 2;
    strcpy(emp[1].name, "taylor");
    emp[1].age = 26;
    emp[1].salary = 36000.0f;

    emp[2].id = 3;
    strcpy(emp[2].name, "swift");
    emp[2].age = 31;
    emp[2].salary = 90000.0f;
}


void emp_writefile(employee_t emp[], int n, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if(!fp) {
        perror("fopen (write)");
        exit(EXIT_FAILURE);
    }
    fwrite(emp, sizeof(employee_t), n, fp);
    fclose(fp);
}


void emp_readfile(employee_t emp[], int n, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if(!fp) {
        perror("fopen (read)");
        exit(EXIT_FAILURE);
    }
    fread(emp, sizeof(employee_t), n, fp);
    fclose(fp);
}
