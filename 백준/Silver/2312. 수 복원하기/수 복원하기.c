#include <stdio.h>
#include <stdbool.h>
#include <memory.h>
#define MAX_N 100000

int N;
bool isPrime[MAX_N + 5];
int cnt[MAX_N + 5];

void input() {
    scanf("%d", &N);
}

void eratos() {
    for (int i = 1; i <= MAX_N; ++i) {
        isPrime[i] = true;
    }    
    
    for (int i = 2; i <= MAX_N; ++i) {
        if (isPrime[i]) {
            for (int j = i * 2; j <= MAX_N; j += i)
                isPrime[j] = false;
        }
    }
}

void solve() {
    memset(cnt, 0, sizeof(cnt));
    int num = N;
    for (int i = 2; i <= N; ++i) {
        if (isPrime[i]) {
            while (num % i == 0) {
                num /= i;
                cnt[i]++;
            }
        }
    }
}

void output() {
    for (int i = 2; i <= N; ++i) {
        if (cnt[i]) 
            printf("%d %d\n", i, cnt[i]);
    }
}

int main() {
    
    int T; scanf("%d", &T);
    eratos();
    
    for (int tc = 1; tc <= T; ++tc) {
        input();
        solve();
        output();
    } 
    
    return 0;
}