#include <bits/stdc++.h>
using namespace std;
int tmp[10001];
// 값이 0이면 null과 동일
void postorder(int startIdx, int endIdx) {
    if (startIdx == endIdx) return;
	if (startIdx == endIdx - 1) {
		cout << tmp[startIdx] << "\n";
		return;
	}
	int idx = startIdx + 1;
	// 값이 큰 게 나올 때 까지 idx++
	while (idx < endIdx) {
		if (tmp[startIdx] < tmp[idx]) break;
		idx++;
	}
	
	// Divide-Conquer
	// 왼쪽에는 node보다 작은 BST
	postorder(startIdx+1, idx);
	// 오른쪽에는 node보다 큰 BST
	postorder(idx, endIdx);
	// 후위 순회
	cout << tmp[startIdx] << "\n";
}


int main() {
	int N, cnt = 0;
	while (cin >> N) {
        tmp[cnt++] = N;
    }
	
	postorder(0, cnt);
}