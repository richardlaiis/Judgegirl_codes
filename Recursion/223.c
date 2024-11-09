#include <stdio.h>
#include <assert.h>
typedef struct point {
    int x, y;
} Point;
// lb: left-bottom
// rt: right-top
// miss: codinate of missed tile
int find_quadrant(Point lb, Point rt, Point miss) {
    int n = rt.x-lb.x;
    Point c = {lb.x+n/2, lb.y+n/2}; // center
    if(miss.x > c.x && miss.y > c.y) return 1;
    else if(miss.x <= c.x && miss.y > c.y) return 2;
    else if(miss.x <= c.x && miss.y <= c.y) return 3;
    else return 4;
}
void fill(Point lb, Point rt, Point miss, int bx, int by) {
    assert(rt.x-lb.x == rt.y-lb.y);
    if(lb.x >= bx && lb.y >= by) {
        return;
    }
    int n = rt.x-lb.x;
    int type = find_quadrant(lb, rt, miss);
    if(n == 2) {
        printf("%d %d %d\n", type, (lb.x+rt.x)/2, (lb.y+rt.y)/2);
        return;
    }
    printf("%d %d %d\n", type, (lb.x+rt.x)/2, (lb.y+rt.y)/2);
    Point nlb, nrt; // new lb and rt
    nlb.x = lb.x+n/2, nlb.y = lb.y+n/2;
    nrt = rt;
    if(type == 1) {
        fill(nlb, nrt, miss, bx, by);
    }else {
        fill(nlb, nrt, nlb, bx, by);
    }
    nlb.x = lb.x, nlb.y = lb.y+n/2;
    nrt.x = lb.x+n/2, nrt.y = rt.y;
    if(type == 2) {
        fill(nlb, nrt, miss, bx, by);
    }else {
        Point nmiss; // new miss;
        nmiss.x = lb.x+n/2;
        nmiss.y = lb.y+n/2+1;
        fill(nlb, nrt, nmiss, bx, by);
    }
    nlb = lb;
    nrt.x = lb.x+n/2, nrt.y = lb.y+n/2;
    if(type == 3) {
        fill(nlb, nrt, miss, bx, by);
    }else {
        fill(nlb, nrt, nrt, bx, by);
    }
    nlb.x = lb.x+n/2, nlb.y = lb.y;
    nrt.x = rt.x, nrt.y = lb.y+n/2;
    if(type == 4) {
        fill(nlb, nrt, miss, bx, by);
    }else {
        Point nmiss;
        nmiss.x = lb.x+n/2+1;
        nmiss.y = lb.y+n/2;
        fill(nlb, nrt, nmiss, bx, by);
    }

}
int main() {
    int l, m;
    scanf("%d%d", &l, &m);
    Point lb = {0, 0}, rt = {l, l}, miss = {l-m+1, l-m+1};
    fill(lb, rt, miss, l-m, l-m);
}