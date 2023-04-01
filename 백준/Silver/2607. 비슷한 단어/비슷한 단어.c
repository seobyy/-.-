#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int N, cnt = 0, A[26] = {0}; 
    char a[11], b[11];
    scanf("%d %s", &N, a);
    int la = strlen(a);
    for (int i = 0; i < la; ++i) 
        A[a[i] - 'A']++;
    for (int i = 1; i < N; ++i) {
        int B[26] = {0};
        scanf("%s", b);
        int lb = strlen(b);
        int x = 0;
        if (abs(la - lb) > 1)
            continue;
        for (int j = 0; j < lb; ++j) 
            B[b[j] - 'A']++;
        for (int j = 0; j < 26; ++j) {
            int y = abs(A[j] - B[j]);
            if (y > 1) {
                x = 3; break;
            }
            else
                x += y;
        }
        if (x <= 2)
            cnt++;
    }
    printf("%d", cnt);
}