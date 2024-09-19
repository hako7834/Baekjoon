#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001], dp[1001];

int main() {
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) cin >> arr[i];

    fill(begin(dp), end(dp), 1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    int inc[1001];
    copy(begin(dp), end(dp), begin(inc));
    fill(begin(dp), end(dp), 1);
    for (int i = N - 1; i >= 0; i--) {
        for (int j = N - 1; j > i; j--) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int maxLength = 0;
    for (int i = 0; i < N; i++) {
        maxLength = max(maxLength, inc[i] + dp[i] - 1);
    }

    cout << maxLength << endl;
    return 0;
}
