#include <stdint.h>
#include <string.h>
#include <stdio.h>
void MorseEncode(int* n, char str[], uint64_t* encoded_content) {
    char* MorseCodes[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    int slen = strlen(str);
    uint64_t tmp = 0;
    uint64_t cur;
    int curpos = 63;
    for(int i = 0; i < slen; i++) {
        char code[7];
        strcpy(code, MorseCodes[str[i]-'A']);
        int codelen = strlen(code);
        code[codelen] = '\0';
        for(int j = 0; j < codelen; j++) {
            if(code[j] == '.') cur = 0ULL;
            else if(code[j] == '-') cur = 1ULL;
            tmp |= cur<<(curpos-1);
            curpos-=2;
            if(curpos<0) {
                encoded_content[(*n)++] = tmp;
                tmp = 0ULL;
                curpos = 63;
            }
        }
        if(i == slen-1) continue;
        cur = 2ULL;
        tmp |= cur<<(curpos-1);
        curpos -= 2ULL;
        if(curpos<0) {
            encoded_content[(*n)++] = tmp;
            tmp = 0ULL;
            curpos = 63;
        }
    }
    if(curpos!=63 && curpos>0) {
        cur = 3ULL;
        while(curpos > 0) {
            tmp |= cur<<(curpos-1);
            curpos-=2;
        }
        encoded_content[(*n)++] = tmp;
    }
}
