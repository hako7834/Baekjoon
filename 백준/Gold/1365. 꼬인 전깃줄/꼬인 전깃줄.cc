#include <iostream>
using namespace std;
int lis[100001], arr[100001];
int binarySearch(int left, int right, int target) {
    while (left < right) {
        int mid = (left+right)/2;
        if (lis[mid] < target) left = mid + 1;
        else right = mid;
    }
    return right;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int k = 0; k < N; k++) cin >> arr[k];
    int j = 0; // lis 탐색의 현재 위치
    lis[0] = arr[0];
    for (int i = 1; i < N; i++) {
        if (lis[j] < arr[i]) {
            lis[j+1] = arr[i];
            j++;
        }
        else {
            lis[binarySearch(0, j, arr[i])] = arr[i];
        }
    } // O(nlogn)
    int lis_size = j + 1;
    cout << N - lis_size;
}