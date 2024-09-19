#include <bits/stdc++.h>
using namespace std;
pair<int, int> tree[1000001];
vector<int> tmp;
// 값이 0이면 null과 동일
void postorder(int curr) {
    if (curr == 0) return;
	if (curr >= 1000001) return;
    postorder(tree[curr].first);
    postorder(tree[curr].second);
    cout << curr << "\n"; // 후위
}

void makeBst(int curr, int n) { // curr: 현재 노드, n: 넣을 값
	if (n == 0) return;
	if (curr == 0) return;
	if (curr >= 1000001) return;
	if (n > curr) {
        if (tree[curr].second == 0) tree[curr].second = n;
        else makeBst(tree[curr].second, n);
    } else {
        if (tree[curr].first == 0) tree[curr].first = n;
        else makeBst(tree[curr].first, n);
    }
}


int main() {
	int N;
	while (cin >> N) {
        tmp.push_back(N);
    }
	fill(begin(tree), end(tree), make_pair(0, 0));

	int root = tmp[0];
	for (int i = 1; i < tmp.size(); i++) {
		makeBst(root, tmp[i]);
	}
	postorder(root);
}