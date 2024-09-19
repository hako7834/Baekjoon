#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> tree[1001];
bool visited[1001] = { false, };
int dist[1001];
int startDist[1001];

void dijkstra(priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>& pq) {
	while (!pq.empty()) {
        int curr = pq.top().second;
        int currDist = pq.top().first;
        pq.pop();

        if (visited[curr]) continue;
        visited[curr] = true;

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
	int N, M, X;
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		int u, v, t;
		cin >> u >> v >> t;
		tree[u].push_back({t, v});
	}
	fill(begin(dist), end(dist), 10000001);
	dist[X] = 0;
	// Dijkstra Algorithm
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	// X 에서 출발
	pq.push({0, X});
	dijkstra(pq);
	// 값 복사
	for (int i = 0; i <= N; i++) {
		startDist[i] = dist[i];
	}
	// n에서 X로 가는 최단거리를 저장하는 배열
	int temp[1001] = {0, };
	// X 에 도착
	for (int j = 1; j <= N; j++) {
		if (j == X) continue;
		// init
		fill(begin(dist), end(dist), 10000001);
		fill(begin(visited), end(visited), false);
		
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push({startDist[X], j});
		dijkstra(pq);

		if (dist[X] != 10000001) temp[j] = dist[X];
	}
	
	int m = temp[1] + startDist[1];
    for (int i = 2; i <= N; i++) {
        m = max(m, temp[i] + startDist[i]);
    }
	cout << m;
}