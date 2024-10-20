#include <bits/stdc++.h>
using namespace std;
int main() {
    int arr[2001];
    int N;
    cin >> N;
    for (int i = 0; i < 1000; i++) {
        arr[i] = 1;
    }
    for (int i = 1000; i < 2000; i++) {
        arr[i] = 1000;
    }

    cout << 2000 << "\n";
    for (int i = 0; i < 2000; i++) {
        cout << arr[i] << " ";
    }
}