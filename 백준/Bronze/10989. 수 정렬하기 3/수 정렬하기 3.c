#include <stdio.h>

int main() {
    int N, num, cnt[10001] = {0};
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &num);
        cnt[num]++;
    }
    for (int i = 1; i <= 10000; ++i) {
        if (cnt[i] != 0) {
            for (int j = 0; j < cnt[i]; ++j)
                printf("%d\n", i);
        }
    }
    return 0;
}