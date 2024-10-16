#include <bits/stdc++.h>
using namespace std;
int arr[100001];

int main() {

    int N, S;
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int l = 0, r = 1;
    long long currSum = arr[0];
    int currMin = 100000001;
    while (1) {
        if (currSum < S) {
            if (r == N) break;
            currSum += arr[r++];
        } else {
            if (r - l < currMin) {
                currMin = r - l;
            }
            currSum -= arr[l++];
        }
    }
    if (currMin == 100000001) cout << 0;
    else cout << currMin;
}