#include <iostream>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 8
using namespace std;

int N, M;
int selected[MAX_N + 2];
int nums[MAX_N + 2];

void backtracking(int num, int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; ++i)
            cout << nums[i] << ' ';
        cout << '\n';
        return;
    }
    
    for (int i = 1; i <= N; ++i) {
        if (!selected[i]) {
            selected[i] = true;
            nums[cnt] = i;
            backtracking(i + 1, cnt + 1);
            selected[i] = false;
        }
    }
}


int main() {
    
    fastio;
    cin >> N >> M;
    
    backtracking(1, 0);
    
    return 0;
}