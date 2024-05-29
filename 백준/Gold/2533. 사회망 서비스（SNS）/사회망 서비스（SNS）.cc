#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
vector<int> children[1000001];
int dp[1000001][2] = {0,}; // [정점 개수][얼리 어답터 여부] -> 벽 부수기 처럼...
class Graph{
public:
    int N; // node
    vector<vector<int>> adj; // linked-list

    Graph(): N(0){}
    Graph(int n): N(n) { adj.resize(N+1); }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void sortList() {
        for (int i = 0; i < N; i++)
            sort(adj[i].begin(), adj[i].end());
    }
    void makeTree(int root) {
        vector<bool> v(N+1, false);
        queue<int> q;
        v[root] = true;
        q.push(root);
        // start
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int next: adj[curr]) {
                if (!v[next]) {
                    v[next] = true;
                    q.push(next);
                    children[curr].push_back(next); // curr의 자녀들: next
                }
            }
        }
    }
};

// top-down?
// curr가 얼리어답터면 children[curr]들은 얼리어답터일 필요가 없음

// dp[node][bool]: 해당 node가 bool상태일 때 얼리어답터 수
// sns = min(curr가 얼리어답터인 경우, 아닌 경우)
int sns(int curr, bool pick) {
    int &ret = dp[curr][pick];
    if (ret != 0) return ret;
    int no = 1, yes = INF;
    // 얼리어답터가 아닌 경우, 자녀들은 얼리어답터여야만 한다. 
    // 얼리어답터인 경우도 자녀들이 얼리어답터인 경우를 고려해야만 한다...
    for (int next: children[curr])
        no += sns(next, true);
    // 얼리어답터인 경우, 자녀들은 모름. (얼리어답터일 수도 있고, 아닐 수도 있고...)
    if (pick) {
        yes = 0;
        for (int next: children[curr])
            yes += sns(next, false);
    }

    // 자녀가 얼리어답터인지 아닌지 모르므로, 둘다 고려해보자.
    return ret = min(yes, no);
}


int main() {
    int N;
    cin >> N;
    Graph G(N);
    // 1. 그래프 그리기
    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        G.addEdge(u, v);
    }
    G.sortList();
    // 2. 트리 제작 (root = 1)
    G.makeTree(1);
    cout << sns(1, true);
}