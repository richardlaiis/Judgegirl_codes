#define MAX 500
#include <stdio.h>
void rotate(int *P[MAX][MAX], int n) {
    int *temp[MAX][MAX];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            temp[i][j] = P[n-j-1][i];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            P[i][j] = temp[i][j];
        }
    }
}