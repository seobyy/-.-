#include <iostream>
#include <vector>
#include <algorithm>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 500'000
using namespace std;

int nA, nB;
int target;
int A[MAX_N + 5];
int B[MAX_N + 5];
vector <int> v;

void binarySearch(int s, int e) {
    
    if (s > e) {
        v.push_back(target);
        return;
    }
    
    int mid = s + (e - s) / 2;
    
    if (B[mid] < target)
        binarySearch(mid + 1, e);
    else if (B[mid] > target)
        binarySearch(s, mid - 1);
    else 
        return;

}

int main() {
    
    fastio;
    cin >> nA >> nB;
    
    for (int i = 0; i < nA; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < nB; ++i) {
        cin >> B[i];
    }
    
    sort(B, B + nB);
    for (int i = 0; i < nA; ++i) {
        target = A[i];
        binarySearch(0, nB - 1);
    }
    
    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for (auto i : v) {
        cout << i << ' ';
    }
    cout << '\n';
    
    return 0;
}