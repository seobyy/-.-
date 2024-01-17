#include <iostream>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 1024
using namespace std;

int A[MAX_N + 2][MAX_N + 2];
int sumA[MAX_N + 2][MAX_N + 2];

int main() {
    
    fastio;
    int N, M;
    cin >> N >> M;
    
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> A[i][j];
            sumA[i][j] = sumA[i - 1][j] + sumA[i][j - 1] - sumA[i - 1][j - 1] + A[i][j];
        }
    }
    for (int i = 0; i < M; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        cout << sumA[x2][y2] - sumA[x1 - 1][y2] - sumA[x2][y1 - 1] + sumA[x1 - 1][y1 - 1] << '\n';
    }
    
    return 0;
}