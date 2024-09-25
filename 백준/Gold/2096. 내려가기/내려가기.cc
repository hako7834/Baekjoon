#include <bits/stdc++.h>
using namespace std;
int maxDp[3] = {0, };
int minDp[3] = {0, };
int tmp_0, tmp_2;
int main() {
    int N;
    cin >> N;
    cin >> maxDp[0] >> maxDp[1] >> maxDp[2];
    for (int i = 0; i < 3; i++) {
        minDp[i] = maxDp[i];
    }

    for (int i = 1; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        tmp_0 = maxDp[0];
        tmp_2 = maxDp[2];
        maxDp[0] = max(maxDp[0], maxDp[1]) + a;
        maxDp[2] = max(maxDp[1], maxDp[2]) + c;
        maxDp[1] = max(max(tmp_0, maxDp[1]), tmp_2) + b;

        tmp_0 = minDp[0];
        tmp_2 = minDp[2];
        minDp[0] = min(minDp[0], minDp[1]) + a;
        minDp[2] = min(minDp[1], minDp[2]) + c;
        minDp[1] = min(min(tmp_0, minDp[1]), tmp_2) + b;
    }
    int maxValue = max(max(maxDp[0], maxDp[1]), maxDp[2]);
    int minValue = min(min(minDp[0], minDp[1]), minDp[2]);
    cout << maxValue << " " << minValue;
}