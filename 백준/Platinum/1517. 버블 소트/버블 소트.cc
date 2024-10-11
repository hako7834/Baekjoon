#include <bits/stdc++.h>
using namespace std;

long long tree[2000003] = {0,}; // 세그먼트 트리 크기 2 * N으로 설정
int N;
int sortedArr[500001];

// 좌표 압축
void cc(int *p) {
    for (int i = 0; i < N; i++) {
        sortedArr[i] = p[i];
    }

    sort(sortedArr, sortedArr + N);
    int size = unique(sortedArr, sortedArr + N) - sortedArr;

    unordered_map<int, int> compressed;
    for (int i = 0; i < size; ++i) {
        compressed[sortedArr[i]] = i;
    }

    for (int i = 0; i < N; ++i) {
        p[i] = compressed[p[i]];
    }
}

void update(int index, long long num) {
    index += N; // 세그먼트 트리의 위치로 이동
    tree[index] += num; // 기존 값에 추가
    while (index > 1) {
        index /= 2;
        tree[index] = tree[2 * index] + tree[2 * index + 1]; // 부모 노드 업데이트
    }
}

// l ~ r 까지의 구간합 return
long long prefix(int l, int r) {
    long long result = 0;
    l += N; // 인덱스 조정
    r += N; // 인덱스 조정
    while (l <= r) {
        if (l % 2 == 1) {
            result += tree[l]; // l번째 노드 포함
            l++;
        }
        if (r % 2 == 0) {
            result += tree[r]; // r번째 노드 포함
            r--;
        }
        l /= 2; // 부모로 이동
        r /= 2; // 부모로 이동
    }
    return result;
}

int main() {
    int arr[500001];
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    cc(arr); // 좌표 압축
    
    // arr[0] 부터 시작
    update(arr[0], 1);
    long long cnt = 0;
    int size = unique(sortedArr, sortedArr + N) - sortedArr; // 압축된 사이즈
    for (int i = 1; i < N; i++) {
        cnt += prefix(arr[i] + 1, size - 1); // 현재 원소보다 큰 수의 개수를 계산
        update(arr[i], 1); // 해당 원소의 카운트 업데이트
    }
    
    cout << cnt; // 결과 출력
}
