#include <stdio.h>
#define MAX 1000
 
void permute(int *ptrArray[MAX], int *ptrPerms[MAX]) {
    int n = 0;
    while(ptrArray[n] != NULL) {
        n++;
    }
    int m = 0;
    while(ptrPerms[m] != NULL) {
        m++;
    }
    int *prev[MAX];
    for(int i = 0; i < n; i++) {
        prev[i] = ptrArray[i];
    }
    int *cur[MAX];
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cur[j] = prev[ptrPerms[i][j]];
        }
        for(int j = 0; j < n; j++) {
            prev[j] = cur[j];
        }
    }
    for(int i = 0; i < n; i++) {
        ptrArray[i] = cur[i];
    }
}