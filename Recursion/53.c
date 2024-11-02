#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void printArr(int a[], int n) {
    for(int i = 0; i < n-1; i++) {
        printf("%d ",a[i]);
    }
    printf("%d\n",a[n-1]);
}
void permute(int a[], int n, int idx) {
    if(idx == n-1) {
        printArr(a, n);
        return;
    }
    for(int i = idx; i < n; i++) {
        swap(&a[idx], &a[i]);
        int temp[n];
        for(int j = 0; j < n; j++) temp[j] = a[j];
        qsort(a+idx+1, n-idx-1, sizeof(int), cmp);
        permute(a, n, idx+1);
        for(int j = 0; j < n; j++) a[j] = temp[j];
        swap(&a[idx], &a[i]);
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int a[9];
    for(int i = 0; i < n; i++) {
        scanf("%d", a+i);
    }
    qsort(a, n, sizeof(int), cmp);
    //printArr(a, n);
    permute(a, n, 0);
}