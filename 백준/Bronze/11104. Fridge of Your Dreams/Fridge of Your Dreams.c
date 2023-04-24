#include <stdio.h>
#include <math.h>

int main() {
    int n;
    char cola[24];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", cola);
        int sum = 0;
        for (int j = 0; j < 24; ++j) {
            if (cola[j] == '1')
                sum += pow(2, 23 - j);
        }
        printf("%d\n", sum);
    }
}