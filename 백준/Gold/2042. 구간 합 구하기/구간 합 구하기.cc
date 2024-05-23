#include <bits/stdc++.h>
using namespace std;
// 이진 트리 -> 삽입, 삭제: O(1)
// 그냥 list 쓰면 O(N)임...
long long leaf[1000001] = {0,}, tree[2000001] = {0,};
int N, M, K;
// N <= loc <= 2*N-1
void segment() {
    for (int i = 0; i < N; i++) tree[N + i] = leaf[i];
    for (int i = N-1; i > 0; i--) tree[i] = tree[2 * i] + tree[2 * i + 1];
} // 세그먼트 트리 제작

void update(int index, long long num) {
    index += N;
    tree[index] = num;
    while (index > 1) {
        index /= 2;
        tree[index] = tree[2 * index] + tree[2 * index + 1];
        // parent 값 채우기
    }
}

// 구간 합 구하기
long long prefix(int l, int r) {
    long long result = 0;
    l += N;
    r += N; // 제일 밑으로 옮기기
    while (l <= r) {
        if (l%2 == 1) { // 홀수면
            result += tree[l]; // 부분을 더하고
            l++;
        }
        if (r%2 == 0) {
            result += tree[r];
            r--;
        }
        l /= 2;
        r /= 2; // 점점 위로 올리며 반복
    }
    return result; // 이걸 재귀로 구현할 수도 있음.
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> M >> K; // leaf, change, prefix-sum
    // 홀수면 0 추가 필요.
    for (int i = 0; i < N; i++) {
        long long tmp;
        cin >> tmp;
        leaf[i] = tmp;
    }
    segment();
    for (int i = 0; i < M+K; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        // a == 1이면 update, a == 2면 prefix
        if (a == 1) {
            update(b-1, c);
        }
        if (a == 2) {
            cout << prefix(b-1, c-1) << "\n";
        }
    }
}