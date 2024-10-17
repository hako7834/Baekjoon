#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
bool isVis[1001] = {0, };
stack<int> gvis;
vector<bool> isInStack;
bool hasCycle = false;


void dfs(int root) {
    if (root == 0) return;
    isVis[root] = true;
    isInStack[root] = true;

    for (auto &num : g[root]) {
        if (!isVis[num]) dfs(num);
        else if (isInStack[num]) { // 현재 스택에 있으면 사이클 발생
            hasCycle = true;
            return;
        }
    }

    gvis.push(root);
    isInStack[root] = false;
}

void dfs_all(int n) {
    for (int i = 1; i <= n; i++) {
        if (!isVis[i]) dfs(i);
        if (hasCycle) {
            break;
        }
    }
}


int main() {
    int N, M;
    cin >> N >> M;
    g.resize(N+1, vector<int>(N+1));
    isInStack.resize(N + 1, false);
    for (int i = 0; i < M; i++) {
        int cnt;
        cin >> cnt;
        int tmp;
        cin >> tmp;
        for (int j = 1; j < cnt; j++) {
            int n;
            cin >> n;
            g[tmp].push_back(n);
            tmp = n;
        }
    }
    dfs_all(N);
    if (hasCycle) {
        cout << 0;
        return 0;
    }
    while (!gvis.empty()) {
        cout << gvis.top() << "\n";
        gvis.pop();
    }
}