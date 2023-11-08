#include <iostream>
#include <vector>
#include <algorithm>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 50
using namespace std;

int N;
int score;
int outCnt;
int ans;

int record[MAX_N + 5][10];
int order[10];
bool base[5];

void cleanBase() {
    for (int i = 1; i <= 3; ++i)
        base[i] = false;
}

void batting(int type) {
    
    if (type == 0)
        outCnt++;
    
    else if (type == 1) {
        if (base[3]) 
            score++;
        
        for (int i = 2; i >= 1; --i) 
            base[i + 1] = base[i];
        
        base[1] = true;
    }
    
    else if (type == 2) {
        for (int i = 3; i >= 2; --i) {
            if (base[i]) 
                score++;
        }
        base[3] = base[1];
        base[1] = false;
        base[2] = true;
    }
    
    else if (type == 3) {
        for (int i = 1; i <= 3; ++i) {
            if (base[i]) 
                score++;
            base[i] = false;
        }
        base[3] = true;
    }
    
    else if (type == 4) {
        for (int i = 3; i >= 1; --i) {
            if (base[i])
                score++;
            base[i] = false;
        }
        score++;
    }
}

void playBaseball() {
    score = 0;
    int next = 1;
    for (int i = 1; i <= N; ++i) {
        outCnt = 0;
        cleanBase();
        while (outCnt < 3) {
            batting(record[i][order[next]]);
            next++;
            if (next == 10)
                next = 1;
        }
    }
    
    if (score > ans)
        ans = score;
}

int main() {
    
    fastio;
    cin >> N;
    
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= 9; ++j) {
            cin >> record[i][j];
        }
    }
    
    // 1. 타순 정하기
    vector <int> v;
    for (int i = 2; i <= 9; ++i)
        v.push_back(i);
    
    do {
        order[4] = 1;
        for (auto i : v) {
            for (int j = 1; j <= 9; ++j) {
                if (!order[j]) {
                    order[j] = i;
                    break;
                }
            }
        }

        // 2. 각 타순에 대해 야구 시뮬레이션 실행
        playBaseball();
        for (int i = 1; i <= 9; ++i)
            order[i] = 0;
    }while(next_permutation(v.begin(), v.end()));
    

    // 3. 최대 점수를 출력
    cout << ans << '\n';
     
    return 0;
}