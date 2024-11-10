#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int place_queen(int idx, int queen_pos[8], char board[8][10]) {
    int ans = 0;
    if(idx == 8) {
        return 1;
    }
    for(int i = 0; i < 8; i++) {
        bool ok = 1;
        if(board[idx][i] == '*') {
            continue;
        }
        for(int j = 0; j < idx && ok; j++) {
            if(queen_pos[j] == i || abs(j-idx) == abs(queen_pos[j]-i)) ok = 0;
        }
        if(ok) {
            queen_pos[idx] = i;
            ans += place_queen(idx+1, queen_pos, board);
        }
    }
    return ans;
}
int main() {
    char board[8][10];
    int queen_pos[8];
    for(int i = 0; i < 8; i++) scanf("%s", board[i]);
    int ans = place_queen(0, queen_pos, board);
    printf("%d\n", ans);
}