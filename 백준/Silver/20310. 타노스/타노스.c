#include <stdio.h>
#include <string.h>

int main() {
    int cnt_0 = 0, cnt_1 = 0;
    char S[501];
    scanf("%s", S);
    int len = strlen(S);
    for (int i = 0; i < len; ++i) {
        if (S[i] - '0' == 0) 
            cnt_0++;
        else 
            cnt_1++;
    }
    cnt_0 /= 2; cnt_1 /= 2;
    for (int j = 0; j < cnt_0; ++j) {
        printf("0");
    }
    for (int j = 0; j < cnt_1; ++j) {
        printf("1");
    }
}