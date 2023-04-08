#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a > *(int*)b); 
}

int main() {
    int N, L, pos[1001], cnt = 1;
    scanf("%d %d", &N, &L);
    for (int i = 0; i < N; ++i) 
        scanf("%d", &pos[i]);
    qsort(pos, N, sizeof(int), compare);
    int x = pos[0];
    for (int i = 1; i < N; ++i) {
        if (pos[i] <= x + L - 1)
            continue;
        else 
            cnt++;
            x = pos[i];
    }
    printf("%d\n", cnt);
}