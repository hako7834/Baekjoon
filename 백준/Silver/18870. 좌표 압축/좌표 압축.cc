#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    vector<int> v, w;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
        w.push_back(a);
    }
    sort(w.begin(), w.end());
    w.erase(unique(w.begin(), w.end()), w.end());
    for(int i = 0; i < N; i++) {
        int idx = lower_bound(w.begin(), w.end(), v[i]) - w.begin();
        cout << idx << " ";
    }
}