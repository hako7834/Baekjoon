#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    int N, time[501], result[501] = {0, };
    int indegree[501] = {0, };
    vector<int> g[501];
    queue<int> q;
    cin >> N;
    // 입력 받기
    for (int i = 0; i < N; i++) {
        cin >> time[i];
        while (1) {
            // tmp -> i 로 간다.
            int tmp;
            cin >> tmp;
            if (tmp == -1) break;

            indegree[i]++;
            g[tmp - 1].push_back(i);
        }

        // 탐색 시작점 할당
        if (indegree[i] == 0) {
            result[i] = time[i];
            q.push(i);
        }
    }

    // bfs의 성질을 띄네..?
    for (int i = 0; i < N; i++) {
        int curr = q.front();
        q.pop();
        for (int next : g[curr]) {
            result[next] = max(result[next], result[curr] + time[next]);
            // 간선을 제거하고 indegree가 0이 되면 걔도 queue에 넣기
            if (--indegree[next] == 0) q.push(next);
        }
    }

    for (int i = 0; i < N; i++) {
        cout << result[i] << "\n";
    }
}