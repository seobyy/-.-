#include <stdio.h>
#include <string.h>

char ch[1000005];
int main() {
    int cnt = 0, check = 0;
    scanf("%[^\n]s", ch);
    int len = strlen(ch);
    for (int i = 1; i < len - 1; ++i) {
        if (ch[i] == ' ') 
            cnt++;
    }
    if (len == 1 && ch[0] == ' ')
        cnt = -1;
    printf("%d\n", cnt + 1);
}