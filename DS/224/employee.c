#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"
 
void init_storage(Employee **storage, int n)
{
    // allocate memory space to store employee data
    // no need to understand this function now.
 
    (*storage) = (Employee *)malloc(sizeof(Employee) * n);
}
 
void free_storage(Employee **storage)
{
    free(*storage);
    *storage = 0;
}

Employee* find_employee_by_id( Employee *set, int n, int id ) {
    for(int i = 0; i < n; i++) {
        if(set[i].id == id) {
            return &set[i];
        }
    }
}
Employee* find_employee_by_name( Employee *set, int n, const char *first_name, const char *last_name ) {
    for(int i = 0; i < n; i++) {
        if(strcmp(first_name, set[i].first_name) == 0 && strcmp(last_name, set[i].last_name) == 0) {
            return &set[i];
        }
    }
}
Employee* find_root_boss( Employee *set, int n, Employee *employee ) {
    Employee *tmp = employee;
    while(tmp != find_employee_by_id(set, n, tmp->boss_id)) {
        tmp = find_employee_by_id(set, n, tmp->boss_id);
    }
    return tmp;
}
int check_relationship(Employee *set, int n, Employee *A, Employee *B) {
    Employee *tmp = A;
    while(tmp != find_employee_by_id(set, n, tmp->boss_id)) {
        tmp = find_employee_by_id(set, n, tmp->boss_id);
        if(tmp == B) return 1;
    }
    Employee *tmp2 = B;
    while(tmp2 != find_employee_by_id(set, n, tmp2->boss_id)) {
        tmp2 = find_employee_by_id(set, n, tmp2->boss_id);
        if(tmp2 == A) return 2;
    }
    if(find_root_boss(set, n, A) == find_root_boss(set, n, B)) return 3;
    return 4;
}