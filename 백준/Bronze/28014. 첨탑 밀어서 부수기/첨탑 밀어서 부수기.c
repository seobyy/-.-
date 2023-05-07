#include <stdio.h>

int main() {
    int N, H, last = 0, cnt = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &H);
        cnt++;
        if (H < last)
            cnt--;
        last = H;
    }
    printf("%d\n", cnt);
}