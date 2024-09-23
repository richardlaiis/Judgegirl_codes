#include <stdio.h>
#include <stdbool.h>

int arr[100];

bool isPalindrome(int start, int end) {
	if(start==end) return 1;
	int right = end, left = start;
	while(left<right) {
		if(arr[left] != arr[right]) 
			return 0;
		left++;
		right--;
	}
	return 1;
}

int main() {
	int x, idx = 0;
	int st, et, length=0;
	while(scanf("%d",&x)!=EOF) {
		arr[idx] = x;
		idx++;
	}
	for(int i = 0; i < idx; i++) {
		for(int j = 0; j<idx; j++) {
			for(int k = 0; k<idx; k++) {
				if(!(j>=i && k>=j)) continue;
				if(isPalindrome(i,j) && isPalindrome(j+1,k) && k-i+1>length) {
					length = k-i+1;
					st = i;
					et = k;
				}else if(isPalindrome(i,j) && isPalindrome(j+1,k) && k-i+1==length && i>st) {
					st = i;
					et = k;
				}
			}
		}
	}
	for(int i = st; i < et; i++) {
		printf("%d ", arr[i]);
	}
	printf("%d\n", arr[et]);
}
