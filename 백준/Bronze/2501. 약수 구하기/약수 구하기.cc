#include <bits/stdc++.h>
using namespace std;
vector<int> dp;
int main() {
    int N, K;
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        if (!(N%i)) dp.push_back(i);
    }
    if (dp.size() >= K) cout << dp[K-1];
    else cout << 0;
}