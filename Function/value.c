#include "value.h"

int value(int type, int width, int height, int length) {
	if(type!=79 && type!=47 && type!=29 && type!=82 && type!=26 && type!=22) return -1;
	else if(!(width>0 && height>0 && length>0)) return -2;
	int minx;
	if(width>height) minx=height;
	else minx=width;
	if(minx>length) minx=length;
	int ans = 0, p;
	switch(type) {
		case 79:
			p = 30;
			break;
		case 47:
			p = 10;
			break;
		case 29:
			p = 4;
			break;
		case 82:
			p = 5;
			break;
		case 26:
			p = 3;
			break;
		case 22:
			p = 9;
			break;
		default:
			break;
	}
	int V = width*height*length;
	for(int i = 1; i <= minx; i++) {
		if(width%i==0 && length%i==0 && height%i==0) {
			int v = i*i*i;
			int temp = v*p*V;
			if(temp > ans) ans = temp;
		}
	}
	return ans;
}
