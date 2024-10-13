#include <stdio.h>
#define MAX_PTR_ARR_SIZE 1000

int countIntersections(int* ptrArray[]) {
    int count = 0;
    int n = 0;
    while(ptrArray[n] != NULL) n++;
    n--;
    for(int i = 0; i <= n-1; i++) {
        for(int j = i+1; j <= n; j++) {
            if(ptrArray[i]-ptrArray[j]>=0) count++;
            // printf("%d\n",ptrArray[i]-ptrArray[j]);
        } 
    }
    return count;
}