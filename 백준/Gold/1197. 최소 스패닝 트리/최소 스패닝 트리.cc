#include <bits/stdc++.h>
using namespace std;
int parent[10001];
int find(int child) {
	if (parent[child] == child) return child;
	return parent[child] = find(parent[child]);
}
bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return true;
	parent[b] = a;
	return false;
}

int main() {
	// edge 정보를 저장하는 vector
	vector<pair<int, pair<int, int>>> g;
	int V, E, cnt = 0;
	int result = 0;
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		// 무향 연결 그래프
		g.push_back({w, {u, v}});
	}
	// 가중치를 기준으로 sort
	sort(g.begin(), g.end());
	// init
	for (int i = 1; i <= V; i++) parent[i] = i;
	// cnt가 V - 1이 될 때까지 반복
	for (int i = 0; i < g.size(); i++) {
		if (!merge(g[i].second.first, g[i].second.second)) {
			result += g[i].first;
			cnt++;
		}
		if (cnt == V - 1) break;
	}
	cout << result;
}