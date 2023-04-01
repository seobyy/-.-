#include <stdio.h>
#include <string.h>

int main() {
    int N, A1[26] = {0}, cnt = 0;
    char word1[11], word[11];
    scanf("%d", &N);
    scanf("%s", word1);
    int len1 = strlen(word1);
    for (int i = 0; i < len1; ++i) {
        A1[word1[i] - 'A']++;
    }
    for (int i = 1; i < N; ++i) {
        scanf("%s", word);
        int A[26];
        memcpy(A, A1, sizeof(A1));
        int len = strlen(word);
        for (int j = 0; j < len; ++j) {
            A[word[j] - 'A']--;
        }
        int check = 0;
        for (int j = 0; j < 26; ++j) {
            if (check == 2)
                break;
            if (A[j] > 1 || A[j] < -1) {
                check = 2;
                break;
            }
            else if (A[j] == 1) {
                if (check == 1) {
                    check++;
                    break;
                }
                for (int k = j + 1; k < 26; ++k) {
                    if (A[k] == -1) {
                        A[k] = 0;
                        break;
                    }
                }
                check++; 
            }
            else if (A[j] == -1) {
                if (check == 1) {
                    check++;
                    break;
                }
                for (int k = j + 1; k < 26; ++k) {
                    if (A[k] == 1) {
                        A[k] = 0;
                        break;
                    }
                }
                check++;
            }
        }
        if (check != 2)
            cnt++;
    }
    printf("%d", cnt);
}