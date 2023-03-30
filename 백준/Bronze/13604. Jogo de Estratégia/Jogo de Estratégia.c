#include <stdio.h>

int main() {
    int J, R, n, pt[505] = {0}, max = 0, winner = 0;
    scanf("%d %d", &J, &R);
    for (int i = 1; i <= J * R; ++i) {
        scanf("%d", &n);
        pt[i % J] += n;
    }
    pt[J] = pt[0];
    for (int i = 1; i <= J; ++i) {
        if (pt[i] >= max) {
            max = pt[i];
            winner = i;
        }
    }
    printf("%d", winner);
}