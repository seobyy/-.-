#include <stdio.h>

int main() {
    int map[9][9], max = -1, row = 0, column = 0;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            scanf("%d", &map[i][j]);
            if (map[i][j] > max) {
                max = map[i][j];
                row = i + 1;    column = j + 1;
            }
        }
    }
    printf("%d\n%d %d\n", max, row, column);
    return 0;
}