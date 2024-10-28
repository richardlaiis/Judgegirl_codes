#include <stdio.h>
void num2bits(unsigned int x, int arr[32]) {
	int idx = 31;
	for(int i = 0; i < 32; i++) arr[i] = 0;
	while(x > 0) {
		arr[idx--] = x%2;
		x >>= 1;
	}
}
int main() {
	int width, height;
	char one, zero;
	scanf("%d%d", &width, &height);
	scanf(" %c %c", &one, &zero);
	int n = (width*height/32)+(width*height%32 != 0);
	int row = 0, col = 0;
	int idx = 0; // current index in 1-d array
	char ch[2] = {zero, one};
	char map[height][width];
	for(int i = 0; i < n; i++) {
		unsigned int x;
		int bits[32];
		scanf("%u", &x);
		num2bits(x, bits);
		//for(int i = 0; i < 32; i++) printf("%d",bits[i]);
		for(int j = 0; j < 32; j++) {
			if(idx == width*height)
				break;
			map[idx/width][idx%width] = ch[bits[j]];
			idx++;
		}
	}
	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}
