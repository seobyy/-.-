#include <stdio.h>
#include <string.h>

int main() {
    int N;
    char file_name[51], ans[51];
    scanf("%d", &N);
    scanf("%s", ans);
    int len = strlen(ans);
    for (int i = 1; i < N; ++i) {
        scanf("%s", file_name);
        for (int j = 0; j < len; ++j) {
            if (ans[j] != file_name[j])
                ans[j] = '?';
        }
    }
    printf("%s\n", ans);
}