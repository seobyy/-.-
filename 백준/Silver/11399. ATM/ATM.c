#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a > *(int*)b);
}

int main() {
    int N, P[1001], time = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) 
        scanf("%d", &P[i]);
    qsort(P, N, sizeof(int), compare);
    for (int i = 0; i < N; ++i) 
        time += (N - i) * P[i];
    printf("%d\n", time);
}