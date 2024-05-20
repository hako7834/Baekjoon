#include <iostream>
#include <algorithm>
using namespace std;
int N, K;

int main() {
    cin >> N;
    cin >> K;
    // 0 ~ K까지 BS??
    int left = 1;
    int right = K;
    int ans;
    while (left < right) {
        int mid = (left + right) / 2;
        int cnt = 0;
        for (int i = 1; i <= N; i++) {
            cnt += min(N, mid / i); // 1 ~ N 개수
        }
        if (cnt < K) left = mid + 1;
        else right = mid;
    }

    cout << right;
}