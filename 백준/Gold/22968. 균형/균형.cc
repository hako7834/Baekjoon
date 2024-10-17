#include <iostream>
#include <vector>
using namespace std;

// 최대 노드 수
const int MAX_NODES = 1000000000;

vector<int> dp(43, 0);

// Bottom-Up
void maxHeight() {
    dp[0] = 0;
    dp[1] = 1;

    for (int h = 2; h <= 42; ++h) {
        dp[h] = dp[h - 1] + dp[h - 2] + 1; // 최소 노드 수 계산
    }
}

int maxAVLHeight(int V) {
    for (int h = 0; h <= 42; ++h) {
        if (dp[h] > V) {
            return h - 1; // 마지막 높이는 V를 초과하므로 1을 빼줌
        }
    }
    return 42; // V가 10억 이상인 경우
}

int main() {
    maxHeight();
    int T;
    cin >> T;
    while (T--) {
        int V;
        cin >> V;
        cout << maxAVLHeight(V) << "\n";
    }
}
