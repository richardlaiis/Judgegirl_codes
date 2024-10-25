#include <stdio.h>
typedef unsigned long long ull;
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
int main() {
	int x;
	ull b = 0;
	int p[256] = {[1]=0,[2]=1,[4]=2,[8]=3,[16]=4,[32]=5,[64]=6,[128]=7};
	const ull pre[8] = {0xffffffffffffff00, 0xffffffffffff0000, 0xffffffffff000000, 0xffffffff00000000,0xffffff0000000000, 0xffff000000000000, 0xff00000000000000, 0};
	const ull suf[8] = {0, 0x00000000000000ff, 0x000000000000ffff, 0x0000000000ffffff, 0x00000000ffffffff,
0x000000ffffffffff, 0x0000ffffffffffff, 0x00ffffffffffffff};
	while(ReadInt(&x)) {
		int pos = (((b&0x00000000000000ff)==x) | (((b&0x000000000000ff00)>>8)==x)<<1 | (((b&0x000000000ff0000)>>16)==x)<<2 | (((b&0x00000000ff000000)>>24)==x)<<3 | (((b&0x000000ff00000000)>>32)==x)<<4| (((b&0x0000ff0000000000)>>40)==x)<<5 | (((b&0x00ff000000000000)>>48)==x)<<6|(((b&0xff00000000000000)>>56)==x)<<7);
		if(pos == 0) {
			b = (b<<8)|x;
			continue;
		}
		pos = p[pos];
		b = x | b&pre[pos] | ((b&suf[pos])<<8);
	}
	for(int i = 7; i >= 0; i--) {
		printf("%d%c",(b>>(i<<3))&255," \n"[i==0]);
	}
}

