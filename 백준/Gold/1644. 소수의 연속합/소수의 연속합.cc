#include <bits/stdc++.h>
using namespace std;
bool sosu[4000001]; // 1 = 소수, 0 = 소수아님

void sosuFinder() {
    // 초기화
    for (int i = 0; i < 4000001; i++) {
        sosu[i] = true; // 모든 수를 소수로 초기화
    }
    sosu[0] = false;
    sosu[1] = false;

    for (int i = 2; i * i <= 4000000; i++) { // i*i <= 4000000으로 수정
        if (!sosu[i]) continue;
        for (int j = i * i; j <= 4000000; j += i) { // i*i부터 시작
            sosu[j] = false;
        }
    }
}

int main() {
    int N;
    cin >> N;
    sosuFinder();
    int l = 1, r = 1, sum = 0, res = 0;
    while (1) {
        if (!sosu[l]) {
            l++;
            continue;
        }

        if (!sosu[r]) {
            r++;
            continue;
        }
        
        if (sum >= N) sum -= l++;
        else if (r > N) break;
        else sum += r++;

        if (sum == N) res++;
    }
    cout << res;
}
