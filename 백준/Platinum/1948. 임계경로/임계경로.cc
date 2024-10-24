#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> g[10001];
vector<pair<int, int>> rg[10001];
bool isVis[10001] = {0, };
long long earlist_time[10001] = {0, };
long long latest_time[10001];
stack<int> ts;
queue<int> revts;

void dfs(int root) {
    isVis[root] = 1;
    for (auto &next : g[root]) {
        if (!isVis[next.second]) {
            dfs(next.second);
        }
    }
    ts.push(root);
    revts.push(root);
}

void dfs_all(int n) {
    for (int i = 1; i <= n; i++) {
        if (!isVis[i]) dfs(i);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({w, v});
        rg[v].push_back({w, u});
    }
    int start, end;
    cin >> start >> end;

    // 위상정렬!
    dfs_all(n);

    // earlist_time 구하기
    // est(start, u)
    earlist_time[start] = 0;
    while (!ts.empty()) {
        int curr = ts.top();
        ts.pop();

        for (auto &edge : g[curr]) {
            int weight = edge.first;
            int v = edge.second;

            earlist_time[v] = max(earlist_time[v], earlist_time[curr] + weight);
        }
    }

    // latest_time 구하기
    // lst(end, u)
    memset(latest_time, 100000001, sizeof(latest_time));
    latest_time[end] = earlist_time[end];
    while (!revts.empty()) {
        int u = revts.front();
        revts.pop();

        for (auto &edge : rg[u]) {
            int weight = edge.first;
            int v = edge.second;

            latest_time[v] = min(latest_time[v], latest_time[u] - weight);
        }
    }
    int cnt = 0;
    vector<int> criticalVertices;
    for (int i = 1; i <= n; i++) {
        if (earlist_time[i] == latest_time[i]) {
            criticalVertices.push_back(i);
        }
    }

    int roadCount = 0;
    for (int u : criticalVertices) {
        for (auto &edge : g[u]) {
            int v = edge.second;
            // v가 criticalVertices에 포함되어 있는지 확인
            if (find(criticalVertices.begin(), criticalVertices.end(), v) != criticalVertices.end()) {
                // 임계 경로에 포함되는지 확인
                if (earlist_time[u] + edge.first == earlist_time[v]) {
                    roadCount++;
                }
            }
        }
    }
    cout << earlist_time[end] << "\n" << roadCount;
}