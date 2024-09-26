#include <bits/stdc++.h>
using namespace std;
int pas[31][31];
int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < 31; i++) {
        pas[i][0] = 1;
    }
    for (int i = 1; i < 31; i++) {
        for (int j = 1; j <= i; j++) {
            pas[i][j] = pas[i-1][j-1] + pas[i-1][j];
        }
    }
    cout << pas[n-1][k-1];
}