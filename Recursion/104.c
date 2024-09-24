#include <stdio.h>
#include <stdbool.h>
int da,db,dc;
int ea,eb,ec;
int fa,fb,fc;
bool isAvailable(int x, int y, int z) {
	if((x==da && y==db && z==dc) || (x==ea && y==eb && z==ec) || (x==fa && y==fb && z==fc)) return 1;
	if(!(x-da>=0 && y-db>=0 && z-dc>=0) && !(x-ea>=0 && y-eb>=0 && z-ec>=0) && !(x-fa>=0 && y-fb>=0 && z-fc>=0)) return 0;
	return (isAvailable(x-da, y-db, z-dc) || isAvailable(x-ea, y-eb, z-ec) || isAvailable(x-fa, y-fb, z-fc));
}
void input(int times) {
	if(times==0) {
		return;
	}
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(isAvailable(a, b, c)) printf("yes\n");
	else printf("no\n");
	input(times-1);
}	
int main() {
	scanf("%d%d%d",&da,&db,&dc);
	scanf("%d%d%d",&ea,&eb,&ec);
	scanf("%d%d%d",&fa,&fb,&fc);
	int t;
	scanf("%d",&t);
	input(t);
}
