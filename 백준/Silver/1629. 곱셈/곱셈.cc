#include <bits/stdc++.h>
using namespace std;
// (even) 10^10 = (10^5)^2 = (odd)
int main() {
    long long A, B, C;
    cin >> A >> B >> C;
    long long ans = 1;
    while (B) {
        if (B%2 == 1) { // odd
            ans = (ans * A) % C;
        }
        A = (A*A)%C;
        B /= 2; // 0될 때까지...
    }
    cout << ans%C;
}