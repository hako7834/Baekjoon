#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
long long leaf[1000001], tree[2000001];
int N, M, K;

// N <= loc <= 2*N-1
void segment() {
    for (int i = 0; i < N; i++) tree[N + i] = leaf[i];
    for (int i = N - 1; i > 0; i--) tree[i] = (tree[2 * i] * tree[2 * i + 1]) % MOD;
} // 세그먼트 트리 제작

void update(int index, long long num) {
    index += N;
    tree[index] = num;
    while (index > 1) {
        index /= 2;
        tree[index] = (tree[2 * index] * tree[2 * index + 1]) % MOD;
        // parent 값 채우기
    }
}

// 구간 곱 구하기
long long prefix(int l, int r) {
    long long result = 1;
    l += N;
    r += N; // 제일 밑으로 옮기기
    while (l <= r) {
        if (l % 2 == 1) {
            result = (result * tree[l]) % MOD;
            l++;
        }
        if (r % 2 == 0) {
            result = (result * tree[r]) % MOD;
            r--;
        }
        l /= 2;
        r /= 2; // 점점 위로 올리며 반복
    }
    return result % MOD;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> M >> K; // leaf, change, prefix-sum
    for (int i = 0; i < N; i++) {
        cin >> leaf[i];
    }
    segment();
    for (int i = 0; i < M + K; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        // a == 1이면 update, a == 2면 prefix
        if (a == 1) {
            update(b - 1, c);
        }
        if (a == 2) {
            cout << prefix(b - 1, c - 1) << "\n";
        }
    }
}
