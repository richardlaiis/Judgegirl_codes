void count_collision(int *ptr[], int A[], int n, int a, int b, int c) {
    for(int i = 0; i < c; i++) {
        A[i] = -1;
    }
    for(int i = 0; i < n; i++) {
        int tmp1 = a*i;
        tmp1 %= c;
        int tmp2 = b%c;
        int result = (tmp1 + tmp2)%c;
        ptr[i] = &A[result];
        A[result]++;
    }
    for(int i = 0; i < c; i++) {
        if(A[i] < 0) A[i] = 0;
    }
}