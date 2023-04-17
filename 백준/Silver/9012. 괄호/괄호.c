#include <stdio.h>
#include <string.h>

int main() {
    int T;
    char PS[55];
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        int check = 0;
        scanf("%s", PS);
        int len = strlen(PS);
        for (int j = 0; j < len; ++j) {
            if (PS[j] == '(')
                check++;
            if (PS[j] == ')')
                check--;
            if (check < 0) 
                break;
        }
        printf("%s\n", !check ? "YES" : "NO");
    }
}
