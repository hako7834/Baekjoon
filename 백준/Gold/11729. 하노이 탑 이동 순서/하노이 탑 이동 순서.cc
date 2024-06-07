#include <iostream>
#include <math.h>
using namespace std;
// N-1개의 원판을 B(2)로 옮겨야함
void move(int n, int start, int via, int end) {
    if (n == 1) cout << start << " " << end << "\n";
    else {
        move(n-1, start, end, via);
        cout << start << " " << end << "\n";
        move(n-1, via, start, end);
    }

}


int main() {
    int N;
    cin >> N;
    cout << (long long)(pow(2, N) - 1) << endl;
    move(N, 1, 2, 3);
}