#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001], inc[1001], decr[1001];

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];

    fill(begin(inc), end(inc), 1);
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                inc[i] = max(inc[i], inc[j] + 1);
            }
        }
    }

    fill(begin(decr), end(decr), 1);
    for (int i = N - 2; i >= 0; i--) {
        for (int j = N - 1; j > i; j--) {
            if (arr[j] < arr[i]) {
                decr[i] = max(decr[i], decr[j] + 1);
            }
        }
    }

    int maxLength = 0;
    for (int i = 0; i < N; i++) {
        maxLength = max(maxLength, inc[i] + decr[i] - 1);
    }

    cout << maxLength << endl;
    return 0;
}
