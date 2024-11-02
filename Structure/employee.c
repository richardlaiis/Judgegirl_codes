#include "employee.h"
 
int relation(Employee *employee1, Employee *employee2) {
	Employee *one = employee1;
	Employee *two = employee2;
	while(one->boss != one) {
		if(one->boss == employee2)
			return 1;
		one = one->boss;
	}
	while(two->boss != two) {
		if(two->boss == employee1)
			return 2;
		two = two->boss;
	}
	if(one == two)
		return 3;
	else 
		return 4;
}
