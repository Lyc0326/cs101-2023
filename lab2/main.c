/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>

typedef struct employee {
    
    int em_id;
    char em_name[10];
    int em_age;
    char em_phone[12];
    float em_salary;
    
} employee_t;

void employee_info(employee_t emp_i) {
    printf("emp i id:     %d\n", emp_i.em_id);
    printf("emp i name:   %s\n", emp_i.em_name);
    printf("emp i age:    %d\n", emp_i.em_age);
    printf("emp i phone:  %s\n", emp_i.em_phone);
    printf("emp i salary: %.2f\n", emp_i.em_salary);
    
    return;
}


int main() {
    printf("size of employee_t = %ld\n\n", sizeof(employee_t));
    
    employee_t emp_i;
    
    strcpy(emp_i.em_name, "IU Lee");
    strcpy(emp_i.em_phone, "0937123456");
    emp_i.em_id = 5;
    emp_i.em_age = 18;
    emp_i.em_salary = 1000.30;
    
    employee_info(emp_i);

    return 0;
}
