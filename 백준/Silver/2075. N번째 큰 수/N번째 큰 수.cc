#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    priority_queue<int, vector<int>, greater<>> pq;
    int N;
    cin >> N;
    for (int i = 0; i < N*N; i++) {
        int n;
        cin >> n;
        pq.push(n);
        if (pq.size() > N) {
            pq.pop();
        }
    }
    cout << pq.top();
}