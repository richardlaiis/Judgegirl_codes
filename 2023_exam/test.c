#include <stdio.h>
int main() {
    int N = 3;
    int M = 3;
    int ptrMat[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int* ptrLeft = ptrMat[0];
    int* ptrRight = &ptrMat[2][1];
    int ret = ptrRight - ptrLeft;
    printf("%d\n", ret);
    return 0;
}