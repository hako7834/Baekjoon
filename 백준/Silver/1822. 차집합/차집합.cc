#include <bits/stdc++.h>
using namespace std;
int arr1[500001], arr2[500001];
set<int> arrSet;
int N, M, cnt = 0;
vector<int> ans;
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr1[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> arr2[i];
		arrSet.insert(arr2[i]);
	}
	sort(arr1, arr1 + N);
	// A에는 속하지만 B에는 없는... -> A가 기준
	for (int i = 0; i < N; i++) {
		// iterator가 원소를 찾지 못한 경우
		if (arrSet.find(arr1[i]) == arrSet.end()) {
			cnt++;
			ans.push_back(arr1[i]);
		}
	}
	cout << cnt << "\n";
	for (int num: ans) {
		cout << num << " ";
	}
}