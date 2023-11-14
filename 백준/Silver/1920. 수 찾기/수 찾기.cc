#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 100'000
using namespace std;

int target;
int A[MAX_N + 5];

int binarySearch(int s, int e) {
    
    while (s <= e) {
        int mid = s + (e - s) / 2;
    
        if (A[mid] < target)
            s = mid + 1;
        else if (A[mid] > target)
            e = mid - 1;
        else
            return 1;
    }
    
    return 0;
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
        cin >> target;
        cout << binarySearch(0, N - 1) << '\n';
    }
    
    
    return 0;
}