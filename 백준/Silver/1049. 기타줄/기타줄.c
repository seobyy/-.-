#include <stdio.h>

int main() {
    int N, M, p, u, min_p = 1000, min_u = 1000, ans = 0;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; ++i) {
        scanf("%d %d", &p, &u);
        if (p < min_p)
            min_p = p;
        if (u < min_u)
            min_u = u;
    }
    if (min_u * 6 < min_p)
        ans = N * min_u;
    else {
        int a = (N % 6) * min_u < min_p ? (N % 6) * min_u : min_p;
        ans = (N / 6 * min_p) + a;
    }
    printf("%d\n", ans);
}