#include <bits/stdc++.h>
using namespace std;
int p[1001];
// merge 가능 여부를 return
int find(int child) {
    if (p[child] == child) return child;
    return p[child] = find(p[child]);
}

bool merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    p[b] = a;
    return true;
}

int main() {
    int N, M, cnt = 0, result = 0;
    cin >> N >> M;
    vector<pair<int, pair<int, int>>> g;
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.push_back({w, {u, v}});
    }
    sort(g.begin(), g.end());
    for (int i = 1; i <= N; i++) p[i] = i;
    for (int i = 0; ; i++) {
        if (merge(g[i].second.first, g[i].second.second)) {
            result += g[i].first;
            cnt++;
        }
        if (cnt == N - 1) break;
    }
    cout << result;
}