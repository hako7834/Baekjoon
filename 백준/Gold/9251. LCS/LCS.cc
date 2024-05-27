#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int lcs(string s1, string s2) {
    int l1 = s1.length();
    int l2 = s2.length();
    dp[0][0] = 0;
    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= l2; j++) {
            // 같은 경우, +1만 하면 된다.
            if (s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            // 다른 경우, 이전 lcs길이 중에서 가장 긴거로 유지.
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[l1][l2];
}


int main() {
    string a, b;
    cin >> a >> b;
    cout << lcs(a, b);
}