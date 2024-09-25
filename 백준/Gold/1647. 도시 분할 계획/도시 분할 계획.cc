#include <bits/stdc++.h>
using namespace std;
int p[100001];
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

vector<pair<int, pair<int, int>>> g;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.push_back({w, {u, v}});
    }
    int cnt = 0, result = 0;
    sort(g.begin(), g.end());
    for (int i = 1; i <= N; i++) p[i] = i;
    for (int i = 0; i < g.size(); i++) {
        if (merge(g[i].second.first, g[i].second.second)) {
            result += g[i].first;
            if (++cnt == N - 2) break;
        }
    }
    if (N != 2) cout << result;
    else cout << 0;
}