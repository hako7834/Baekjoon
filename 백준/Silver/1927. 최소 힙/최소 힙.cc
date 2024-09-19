#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	// 꼼수 되나
	priority_queue<int, vector<int>, greater<>> pq;
	int N;
	cin >> N;
	while (N--) {
		int n;
		cin >> n;
		if (n != 0) pq.push(n);
		if (n == 0) {
			if (pq.empty()) cout << 0 << "\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
	}
}