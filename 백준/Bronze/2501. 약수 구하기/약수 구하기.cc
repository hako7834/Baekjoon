#include <iostream>

int tmp[10001] = {0,};
void yaksu(int n) {
    for (int i = 1; i <= n; i++) {
        if (!(n%i)) tmp[i] = 1;
    }
    // i가 n의 약수면 tmp[i] = 1. 아니면 0
}

int search(int N, int K) {
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (tmp[i]) cnt++;
        if (cnt == K) return i;
    }
    return 0;
}

int main() {
    int N, K;
    std::cin >> N >> K;
    yaksu(N);
    std::cout << search(N, K);
}