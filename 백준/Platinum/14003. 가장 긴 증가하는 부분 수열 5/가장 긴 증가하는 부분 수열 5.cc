#include <iostream>
using namespace std;
int lis[1000001], arr[1000001], tmp[1000001], ans[1000001];
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
    tmp[0] = 1;
    for (int i = 1; i < N; i++) {
        if (lis[j] < arr[i]) {
            lis[j+1] = arr[i];
            tmp[i] = j+2;
            j++;
        }
        else {
            int loc = binarySearch(0, j, arr[i]);
            lis[loc] = arr[i];
            tmp[i] = loc + 1;
        }
    } // O(nlogn)
    
    cout << j+1 << "\n";
    int record = j+1;
    for (int i = N-1; i >= 0; i--) {
        if (tmp[i] == record) {
            ans[record] = arr[i];
            record--;
        }
    }
    for (int i = 1; i <= j+1; i++) {
        cout << ans[i] << " ";
    }
    
}