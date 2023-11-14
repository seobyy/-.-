#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 100'000
using namespace std;

int A[MAX_N + 5];

int binarySearch(int s, int e, int target) {
    
    int mid = s + (e - s) / 2;
    
    if (s > e)
        return 0;
    
    if (A[mid] < target)
        return binarySearch(mid + 1, e, target);
    else if (A[mid] > target)
        return binarySearch(s, mid - 1, target);
    else
        return 1;

}

int main() {
    
    fastio;
    int N, M;
    cin >> N;
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    sort(A, A + N);
    
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int x;
        cin >> x;
        cout << binarySearch(0, N - 1, x) << '\n';
    }
    
    
    return 0;
}