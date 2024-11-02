#include "book.h"
#include "date.h" 
#include <stdio.h>
unsigned int library_fine(struct Book book, struct Date date_borrowed, struct Date date_returned) {
	unsigned int total_days_1 = 0;
	unsigned int total_days_2 = 0;
	for(int i = 1; i <= date_borrowed.year-1; i++) {
		total_days_1 += (i%400 == 0 || (i%4 ==0 && i%100 != 0))?366:365;
	}
	for(int i = 1; i <= date_borrowed.month-1; i++) {
		if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
			total_days_1 += 31;
		}else if(i != 2) {
			total_days_1 += 30;
		}else {
			total_days_1 += (28 + (i%400==0 || (i%4==0 && i%100!=0)));
		}
	}
	total_days_1 += date_borrowed.day;
	for(int i = 1; i <= date_returned.year-1; i++) {
		total_days_2 += (i%400 == 0 || (i%4 ==0 && i%100 != 0))?366:365;
	}
	for(int i = 1; i <= date_returned.month-1; i++) {
		if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
			total_days_2 += 31;
		}else if(i != 2) {
			total_days_2 += 30;
		}else {
			total_days_2 += (28 + (i%400==0 || (i%4==0 && i%100!=0)));
		}
	}
	total_days_2 += date_returned.day;
	unsigned int limit[4] = {90, 10, 100, 5};
	unsigned int past = total_days_2-total_days_1+1;
	if(past <= limit[book.type]) return 0;
	else {
		unsigned int idx1 = 100, idx2 = 100;
		for(unsigned int i = 0; i < 32; i++) {
			unsigned int n = book.importance;
			if(n & (1U << i)) {
				if(idx1 == 100) idx1 = i;
				else idx2 = i;
			}
		}
		return (past-limit[book.type])*(idx2-idx1-1);
		
	}
}
/*
int main() {
	struct Book book = {
        "Neon Genesis Evangelion",
        COMICS,
        "978-159-116-400-5",
        "Yoshiyuki Sadamoto",
        17
    };
    struct Date date_borrowed, date_returned;
    date_borrowed.year  = 2004;
    date_borrowed.month = 2;
    date_borrowed.day   = 21;
    date_returned.year  = 2004;
    date_returned.month = 3;
    date_returned.day   = 1;
	printf("%d\n", library_fine(book, date_borrowed, date_returned));
}
*/
