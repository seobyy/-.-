#include <stdio.h>
#include <math.h>

int main() {
    int X, cnt = 0;
    scanf("%d", &X);
    for (int i = 0; i < 7; ++i) {
        if (X == 0)
            break;
        int a = pow(2, 6 - i);
        if (X >= a) {
            X -= a;
            cnt++;
        }
    }
    printf("%d\n", cnt);
}