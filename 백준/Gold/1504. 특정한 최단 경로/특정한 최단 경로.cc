#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> tree[801];
bool visited[801] = { false, };
int dist[801];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
void dijkstra(int n) {
	pq.push({0, n});
	while (!pq.empty()) {
        int curr = pq.top().second;
        int currDist = pq.top().first;
        pq.pop();

        for (const auto& p : tree[curr]) {
            int d = p.first, next = p.second;
            if (dist[next] > currDist + d) {
                dist[next] = currDist + d;
                pq.push({dist[next], next});
            }
        }
    }
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, E;
	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		int u, v, t;
		cin >> u >> v >> t;
		tree[u].push_back({t, v});
		tree[v].push_back({t, u});
	}
	int u, v;
	cin >> u >> v;
	// u에서 출발
	fill(begin(dist), end(dist), 200000001);
	dist[u] = 0;
	dijkstra(u);
	int uDistTo1 = dist[1];
	int uDist = dist[N];
	int uDistToV = dist[v];
	fill(begin(dist), end(dist), 200000001);
	dist[v] = 0;
	dijkstra(v);
	int vDistTo1 = dist[1];
	int vDist = dist[N];

	int ans1 = uDistTo1 + uDistToV + vDist;
	int ans2 = vDistTo1 + uDistToV + uDist;
	int ans = min(ans1, ans2);

	if (ans >= 200000001) cout << -1;
	else cout << ans;
}