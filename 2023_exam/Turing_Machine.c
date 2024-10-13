void Turing_Machine(int *head, int K) {
    int state = 0;
    int step = 0;
    int T[3][4][3] = {
        {{0, 1, 2}, {1, 1, 1}, {2, 1, 2}, {3, 1, 1}},
        {{1, -1, 2}, {2, 1, 0}, {3, -1, 2}, {0, 1, 0}},
        {{2, 0, 1}, {3, -1, 0}, {0, 1, 1}, {1, 0, 0}}
    };
    while(step != K) {
        int nxts = T[state][*head][2];
        int nxtp = T[state][*head][1];
        int write = T[state][*head][0];
        *head = write;
        head += nxtp;
        state = nxts;
        step++;       
    }
}