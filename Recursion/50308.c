#include <stdio.h>
#include <stdbool.h>
typedef struct course {
	int sh, sm; // start hour, start minute
	int eh, em; // end hour, end minute
	int cnt, day; // number of students, day
} Course;
int max(int a, int b) {
	return (a>b)?a:b;
}
bool valid(Course a, Course b) {
	if(a.day != b.day) return 1;
	else {
		int s1 = a.sh*60+a.sm;
		int e1 = a.eh*60+a.em;
		int s2 = b.sh*60+b.sm;
		int e2 = b.eh*60+b.em;
		return (s1 > e2 || s2 > e1);
	}
}
void assign(int cur, int n, int m, Course *lec, int limit[], int *ans, int lec_cnt[], int list[10][10], int duration[], bool ok[70][70], int day_id[], int cnt) {
	if(cur >= cnt) {
		int tot = 0;
		for(int i = 0; i < n; i++) {	
			for(int j = 0; j < lec_cnt[i]; j++) {
				tot += duration[list[i][j]];
			}
		}
		if(tot > *ans) *ans = tot;
		return;
	}
	Course now = lec[day_id[cur]];
	assign(cur+1, n, m, lec, limit, ans, lec_cnt, list, duration, ok, day_id, cnt);
	for(int i = 0; i < n; i++) {
		int conflict = 0;
		if(now.cnt > limit[i]) continue;
		for(int j = 0; j < lec_cnt[i] && !conflict; j++) {
			if(!ok[day_id[cur]][list[i][j]]) conflict = 1;
		}
		if(!conflict) {
			list[i][lec_cnt[i]] = day_id[cur];
			lec_cnt[i]++;
			assign(cur+1, n, m, lec, limit, ans, lec_cnt, list, duration, ok, day_id, cnt);
			lec_cnt[i]--;
		}
	}
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	char temp[20];
	int limit[10];
	Course lec[m+1];
	for(int i = 0; i < n; i++) {
		scanf("%s%d", temp, &limit[i]);
	}
	int duration[m+1];
	int lec_day[6][10], day_cnt[6] = {0};
	for(int i = 0; i < m; i++) {
		scanf("%s%d%d%d%d%d%d", temp, &lec[i].sh, &lec[i].sm, &lec[i].eh, &lec[i].em, &lec[i].cnt, &lec[i].day);
		duration[i] = (lec[i].eh-lec[i].sh)*60+lec[i].em-lec[i].sm+1;

		lec_day[lec[i].day][day_cnt[lec[i].day]++] = i;
	}
	bool ok[70][70] = {0};
	for(int i = 0; i < m; i++) {
		for(int j = i+1; j < m; j++) {
			bool tmp = valid(lec[i], lec[j]);
			ok[i][j] = tmp;
			ok[j][i] = tmp;
		}
	}
	int ans = 0;
	int all = 0;
	int lec_cnt[10] = {0};
	int list[10][10];
	for(int i = 1; i <= 5; i++) {
		assign(0, n, m, lec, limit, &ans, lec_cnt, list, duration, ok, lec_day[i], day_cnt[i]);
		all += ans;
		ans = 0;
		for(int j = 0; j < 10; j++) lec_cnt[j] = 0;
	}
	printf("%d\n", all);
}
