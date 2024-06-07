#include <bits/stdc++.h>
// S < M < L -> 0 1 2로 저장해...
using namespace std;
int arr[1000001], num[1000001];
int main() {
    int J, A, cnt = 0;
    cin >> J;
    cin >> A;
    for (int i = 1; i <= J; i++) {
        char tmp;
        cin >> tmp;
        if (tmp == 'S') arr[i] = 0;
        if (tmp == 'M') arr[i] = 1;
        if (tmp == 'L') arr[i] = 2;
    }
    for (int i = 0; i < A; i++) {
        char tmp;
        int j;
        cin >> tmp >> j;
        int size;
        if (tmp == 'S') size = 0;
        if (tmp == 'M') size = 1;
        if (tmp == 'L') size = 2;
        if (arr[j] != -1 && arr[j] >= size) {
            cnt++;
            arr[j] = -1; // 받음
        }
    }
    cout << cnt;
}