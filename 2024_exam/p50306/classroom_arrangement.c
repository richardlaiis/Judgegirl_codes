#include "classroom_arrangement.h"
#include <stdio.h>
#include <stdbool.h>
typedef struct Classroom Classroom;
typedef struct Course Course;
typedef struct Time Time;
void sort_courses(int schedule[], int cnt, Course *courses) {
    for(int i = cnt-1; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            int idx1 = schedule[j];
            int idx2 = schedule[j+1];
            int d1 = (courses+idx1)->day;
            int d2 = (courses+idx2)->day;
            Time t1 = (courses+idx1)->start;
            Time t2 = (courses+idx2)->start;
            if(d1 > d2) {
                int tmp = schedule[j];
                schedule[j] = schedule[j+1];
                schedule[j+1] = tmp;
                continue;
            }else if(d1 < d2) {
                continue;
            }
            if(t1.hour != t2.hour) {
                if(t1.hour > t2.hour) {
                    int tmp = schedule[j];
                    schedule[j] = schedule[j+1];
                    schedule[j+1] = tmp;
                }
            }else if(t1.minute > t2.minute) {
                int tmp = schedule[j];
                schedule[j] = schedule[j+1];
                schedule[j+1] = tmp;
            }
        }
    }
}
bool overlap(Course *a, Course *b) {
    if(a->day == b->day) {
        if(a->start.hour > b->end.hour) return 0;
        else if(a->start.hour == b->end.hour && a->start.minute > b->end.minute) return 0;
        else if(b->start.hour > a->end.hour) return 0;
        else if(a->end.hour == b->start.hour && b->start.minute > a->end.minute) return 0;
    }
    if(a->day != b->day) return 0;
    return 1;
}
bool available(int schedule[], int cnt, int capacity, Course *a, Course courses[]) {
    if(a->number_of_students > capacity) return 0;
    for(int i = 0; i < cnt; i++) {
        int course_idx = schedule[i];
        if(overlap(a, &courses[course_idx])) {
            return 0;
        }
    }
    return 1;
}
void class_arrangement(int classnum,int coursenum,struct Classroom classrooms[],struct Course courses[]) {
    int coursecnt[500] = {0};
    int schedule[classnum][coursenum];     
    for(int i = 0; i < coursenum; i++) {
        for(int j = 0; j < classnum; j++) {
            if(available(schedule[j], coursecnt[j], classrooms[j].capacity, &courses[i], courses)) {
                schedule[j][coursecnt[j]++] = i;
                break;
            }
        }
    }
    for(int i = 0; i < classnum; i++) {
        if(coursecnt[i] == 0) {
            printf("%s :\n", classrooms[i].name);
            continue;
        }
        printf("%s : ", classrooms[i].name);
        sort_courses(schedule[i], coursecnt[i], courses);
        for(int j = 0; j < coursecnt[i]; j++) {
            printf("%s%c", courses[schedule[i][j]].id, " \n"[j == coursecnt[i]-1]);
        }
    }
}