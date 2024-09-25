#include <bits/stdc++.h>
using namespace std;
int main() {
    int arr[10001];
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int l = 0, r = 0;
    int S = 0, cnt = 0;
    while (1) {
        if (S >= M) S -= arr[l++];
        else if (r == N) break;
        else S += arr[r++];
        
        if(S == M) cnt++;
    }
    cout << cnt;
}