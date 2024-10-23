#include <stdio.h>
int hasEOF = 0;
int readchar() {
    static int N = 1<<20;
    static char buf[1<<20];
    static char *p = buf, *end = buf;
    if(p == end) {
        if((end = buf + fread(buf, 1, N, stdin)) == buf) {
            hasEOF = 1;
            return EOF;    
        }
        p = buf;
    }
    return *p++;
}
int ReadInt(int *x) {
    char c, neg;
    while((c = readchar()) < '-')    {if(c == EOF) return 0;}
    neg = (c == '-') ? -1 : 1;
    *x = (neg == 1) ? c-'0' : 0;
    while((c = readchar()) >= '0')
        *x = (*x << 3) + (*x << 1) + c-'0';
    *x *= neg;
    return 1;
}
int get(long long x, int i) {
	return (x>>(8*i)) % 256;
}
void set(long long *x, int i, int value) {
		
	for(int i = 7; i >= 0; i--) {
		printf("%d%c",get(*x,i)," \n"[i==0]);
	}
	*x &= ~(0xFF << (8*i));
	*x |= ((long long)value << (8*i));
	for(int i = 7; i >= 0; i--) {
		printf("%d%c",get(*x,i)," \n"[i==0]);
	}
}
int main() {
    int x;
	long long shelf = 0;
    /*
	while (ReadInt(&x)) {
		   	
    }
 	*/	
    // output your answer
	for(int i = 7; i >= 0; i--) {
		int k;
		scanf("%d", &k);
		set(&shelf, i, k);
	}
	for(int i = 7; i >= 0; i--) {
		printf("%d%c",get(shelf,i)," \n"[i==0]);
	}
    return 0;
}
