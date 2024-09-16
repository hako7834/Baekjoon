#include <bits/stdc++.h>
using namespace std;
// Tree as Linked-List
// 거의 뭐.. 3차원 배열 급이네..
vector<pair<int, int>> tree[10001];
bool visited[10002] = {false, };
int result = 0;
int endPoint = 0;
void dfs(int n, int currDist) {
	if (visited[n]) return;

	visited[n] = true;
	if (result < currDist) {
		result = currDist;
		endPoint = n;
	}
	for (pair<int, int> p: tree[n]) {
		dfs(p.first, currDist + p.second);
	}
}


int main() {
	int N;
	cin >> N;
	// tree 이므로 edge는 N - 1개...
	for (int i = 1; i < N; i++) {
		int n, m, v;
		cin >> n >> m >> v;
		// a -> b로 갈 때의 가중치 저장
		tree[n].push_back({m, v});
		tree[m].push_back({n, v});
	}
	dfs(1, 0); // 멀리 있는 점
	fill(begin(visited), end(visited), false);
	dfs(endPoint, 0); // 지름
	cout << result;
}