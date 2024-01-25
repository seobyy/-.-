#include <stdio.h>
#include <stdlib.h>

// 오름차순 정렬
int cmp(const void* a, const void* b) {
    return *(int*)a > *(int*)b;
}

int main() {
    int L, n, S[51], cnt = 0, a = 0, b = 0;
    scanf("%d", &L);
    for (int i = 0; i < L; ++i) {
        scanf("%d", &S[i]);
    }
    scanf("%d", &n);
    qsort(S, L, sizeof(int), cmp);
    if (S[0] > n) {
        a = 1; b = S[0] - 1;
    }
    else {
        for (int i = 0; i < L; ++i) {
            if (S[i] == n) {
                printf("%d\n", cnt);
                return 0;
            }
            else if (S[i] > n) {
                b = S[i] - 1; a = S[i - 1] + 1;
                break;
            }
        }
    }
    for (int i = a; i <= n; ++i) {
        for (int j = n; j <= b; ++j) {
            if (i == j)
                continue;
            cnt++;
        }
    }
    printf("%d\n", cnt);
}