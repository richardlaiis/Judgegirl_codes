#include <stdio.h>
#include <stdbool.h>
struct point{
	int x, y;
};

struct point cur_leftdown, cur_righttop;

int area(struct point a, struct point b) {
	return (b.x-a.x)*(b.y-a.y);
}
bool cal_overlap(struct point a, struct point b, struct point c, struct point d) {
	bool flag = 0;

	if(c.x>=a.x && c.x<=b.x) {
		if(c.y>=a.y && c.y<=b.y) cur_leftdown.x = c.x, cur_leftdown.y = c.y, flag=1;
		else if(a.y>=c.y && a.y<=d.y) cur_leftdown.x = c.x, cur_leftdown.y = a.y, flag=1;
		if(d.y>=a.y && d.y<=b.y) cur_leftdown.x = c.x, cur_righttop.y = d.y, flag=1;
		else if(b.y>=c.y && b.y<=d.y) cur_leftdown.x = c.x, cur_righttop.y = b.y, flag=1;
	}else if(a.x>=c.x && a.x<=d.x) cur_leftdown.x = a.x, flag=1;
	if(d.x>=a.x && d.x<=b.x) cur_righttop.x = d.x, flag=1;
	else if(b.x>=c.x && b.x<=d.x) cur_righttop.x = b.x, flag=1;

	return flag;

}
int main() {
	struct point cordinate[3][2];
	int ans = 0;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 2; j++) {
			scanf("%d%d", &cordinate[i][j].x, &cordinate[i][j].y);
		}
		printf("%d\n", area(cordinate[i][0], cordinate[i][1]));
		ans += area(cordinate[i][0], cordinate[i][1]);
	}
	if(cal_overlap(cordinate[0][0], cordinate[0][1], cordinate[1][0], cordinate[1][1]))
		printf("%d\n", area(cur_leftdown, cur_righttop));
		ans -= area(cur_leftdown, cur_righttop);

	if(cal_overlap(cordinate[0][0], cordinate[0][1], cordinate[2][0], cordinate[2][1])) 
		printf("%d\n", area(cur_leftdown, cur_righttop));
		ans -= area(cur_leftdown, cur_righttop);

	if(cal_overlap(cordinate[1][0], cordinate[1][1], cordinate[2][0], cordinate[2][1])) 
		printf("%d\n", area(cur_leftdown, cur_righttop));
		ans -= area(cur_leftdown, cur_righttop);

	printf("(%d,%d), (%d,%d)\n", cur_leftdown.x, cur_leftdown.y, cur_righttop.x, cur_righttop.y);
	if(cal_overlap(cur_leftdown, cur_righttop, cordinate[0][0], cordinate[0][1]))
		printf("(%d,%d), (%d,%d)\n", cur_leftdown.x, cur_leftdown.y, cur_righttop.x, cur_righttop.y);
		printf("%d\n", area(cur_leftdown, cur_righttop));
		ans += area(cur_leftdown, cur_righttop);
	
	printf("%d\n", ans);
}
