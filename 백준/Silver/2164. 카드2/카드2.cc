#include <iostream>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int card[500005];
int main() {
    fastio;
    int N; cin >> N;
    for (int i = 1; i <= N; ++i) 
        card[i] = i;
    while (N > 1) {
        if (N % 2 == 0) {
            for (int i = 1; i <= N / 2; ++i) 
                card[i] = card[2 * i];
            N /= 2;

        }
        else {
            int tmp = card[2];
            for (int i = 1; i < N / 2; ++i) 
                card[i] = card[2 * i + 2];
            card[N / 2] = tmp; 
            N /= 2;
        }
    }
    cout << card[1] << '\n';
}