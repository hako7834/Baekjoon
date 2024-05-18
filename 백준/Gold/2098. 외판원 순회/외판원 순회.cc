#include <iostream>
#include <algorithm>
using namespace std;
const int impossible = 10000001;

int N, arr[16][16], dp[16][1<<16]; // arr[도시][금액], dp[도시][갔냐?], 1 0000 0000 0000 0000 의 상태로 만들었습니다...
int tsp(int curr, int isVis) {
    
    // dp가 비어있고 전부 방문했다면 (dp에 뭔가 넣을 차례일 때)
    if (isVis == (1<<N)-1) {
        if (arr[curr][0] != 0) return arr[curr][0]; // 사이클이면 된다!
        return impossible; // 사이클이 없으면 안됨.
    }
    if (dp[curr][isVis] != -1) return dp[curr][isVis]; // dp
    dp[curr][isVis] = impossible; // min값 찾는거니깐 1000001로 초기화(dp값을!)
    
    for (int i = 0; i < N; i++) {
        if ((isVis & (1<<i)) == (1<<i) || arr[curr][i] == 0) continue;
        // 이미 갔거나 못가면 다음 탐색
        dp[curr][isVis] = min(dp[curr][isVis], tsp(i, isVis | (1<<i)) + arr[curr][i]); // dp에는 최소비용만 들어갈거임.
        // tsp(i, 방문 여부를 true로(비트를 1로))
    }
    return dp[curr][isVis];
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 65536; j++) {
            dp[i][j] = -1;
        }
    }
    cout << tsp(0, 1);
}
