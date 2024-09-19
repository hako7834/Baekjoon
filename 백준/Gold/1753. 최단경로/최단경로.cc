#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> tree[20001];
bool visited[20001] = { false, };
int dist[20001];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int V, E;
	cin >> V >> E;
	int root;
	cin >> root;
	fill(begin(dist), end(dist), 5000000);
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		// u -> v 가중치 w 저장.
		// 정렬을 위해 {w, v} 형태로
		tree[u].push_back({w, v});
	}

	// Dijkstra Algorithm
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[root] = 0;
	pq.push({0, root});
	while (!pq.empty()) {
		int curr;
		// curr 탐색 시작
		// 방문하지 않은 node 탐색하기
		while (!pq.empty()) {
			curr = pq.top().second;
			pq.pop();
			if (!visited[curr]) break;
		}
		if (visited[curr]) break;

		// 탐색 시작
		visited[curr] = true;
		for (pair<int, int> &p: tree[curr]) {
			int d = p.first, next = p.second;
			if (dist[next] > dist[curr] + d) {
				dist[next] = dist[curr] + d;
				pq.push({dist[next], next});
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		if (dist[i] == 5000000) cout << "INF" << "\n";
		else cout << dist[i] << "\n";
	}

}