#include <bits/stdc++.h>
using namespace std;
char korea[5] = {'K', 'O', 'R', 'E', 'A'};
char yonsei[6] = {'Y', 'O', 'N', 'S', 'E', 'I'};
int main() {
    string zom;
    cin >> zom;
    int kp = 0, yp = 0;
    for (int i = 0; ; i++) {
        if (zom[i] == korea[kp]) kp++;
        if (zom[i] == yonsei[yp]) yp++;
        if (kp == 5 || yp == 6) break;
    }
    if (kp == 5) cout << "KOREA";
    else cout << "YONSEI";
}