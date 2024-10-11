#include <bits/stdc++.h>
using namespace std;
const int MAXV = 200000;
const long long MOD = 1000000007;
int N;
long long cnttree[400002] = {0, };
long long sumtree[400002] = {0, };

long long prefix(long long *tree, int l, int r) {
    long long result = 0;
    l += MAXV;
    r += MAXV;
    while (l <= r) {
        if (l % 2 == 1) {
            result += tree[l];
            l++;
        }
        if (r % 2 == 0) {
            result += tree[r];
            r--;
        }
        l /= 2;
        r /= 2;
    }
    return result;
}

void update(long long *tree, int index, int value) {
    index += MAXV;
    tree[index] += value;
    while (index > 1) {
        index /= 2;
        tree[index] = tree[2 * index] + tree[2 * index + 1];
    }
}

int main() {
    long long ans = 1;  // 초기 값 1로 설정
    cin >> N;
    long long x;
    cin >> x;
    update(cnttree, x, 1);
    update(sumtree, x, x);
    for (int i = 1; i < N; i++) {
        cin >> x;
        update(cnttree, x, 1);
        update(sumtree, x, x);

        long long left = prefix(cnttree, 0, x - 1)*x - prefix(sumtree, 0, x - 1);
        long long right = prefix(sumtree, x + 1, MAXV) - prefix(cnttree, x + 1, MAXV)*x;

        if (left + right == 0) {
            ans = 0;
        } else {
            ans *= (left + right) % MOD;
            ans %= MOD;
        }
    }

    cout << ans % MOD;
}