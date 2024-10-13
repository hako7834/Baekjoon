#include <bits/stdc++.h>
using namespace std;
const int MAX = 200000;

int segtree[400004] = {0, };

// init
void init() {
    for (int i = 0; i <= 400002; i++) {
        segtree[i] = 0;
    }
}

void update(int idx, int val) {
    idx += MAX;
    segtree[idx] = val;
    while (idx > 1) {
        idx /= 2;
        segtree[idx] = segtree[2 * idx] + segtree[2 * idx + 1];
    }
}

int prefix(int l, int r) {
    int result = 0;
    l += MAX;
    r += MAX;
    while (l <= r) {
        if (l % 2 == 1) {
            result += segtree[l];
            l++;
        }
        if (r % 2 == 0) {
            result += segtree[r];
            r--;
        }
        l /= 2;
        r /= 2;
    }
    return result;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        // m개의 영화 시청
        int loc[200001];
        int idx = n;
        for (int i = 1; i <= n; i++) {
            loc[i] = idx;
            idx -= 1;
            update(loc[i], 1);
        }

        int query = n;
        for (int i = 1; i <= m; i++) {
            int num;
            cin >> num;
            cout << prefix(loc[num] + 1, query) << " ";
            update(loc[num], 0);
            update(++query, 1);
            loc[num] = query;
        }
        cout << "\n";
        init();
    }
}

// 어려워요 ㅠㅠ

// 5 3 -> 5 4 3 2 1 순서
/**
 * loc = {5 4 3 2 1}
 * 1 2 3 4 5 = idx
 * 1 1 1 1 1
 * 4에서... prefix(loc[4] + 1, 5) = 3
 * update to...
 * 
 * (5 3 2 1 4) 형태
 * loc = {5 4 3 6(new!) 1}
 * 1 2 3 4 5 6(new!) = idx
 * 1 0 1 1 1 1
 * 5에서... prefix(loc[5] + 1, 6) = 4
 * 
 * 식: prefix(loc[N] + 1, query)
 * 
 * 5 3 1 의 경우?
 * loc = {5 4 3 2 1}
 * 1 2 3 4 5
 * 1 1 1 1 1
 * 
 * 5에서... prefix(loc[5] + 1, 5) = 4
 * 나와야함 !!!!!!
 */