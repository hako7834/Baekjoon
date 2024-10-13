#include <bits/stdc++.h>
using namespace std;
stack<pair<int, int>> st;
int main() {
    int N;
    cin >> N;
    int num;
    int same_cnt = 0;
    long long pair_cnt = 0;
    // 시작!
    for (int i = 0; i < N; i++) {
        cin >> num;

        same_cnt = 1;
        // 큰 값이 query되면
        while (!st.empty() && st.top().first < num) {
            // 해당 값의 개수만큼 cnt 증가
            pair_cnt += st.top().second;
            st.pop();
        }

        if (!st.empty()) {
            if (st.top().first == num) {
                pair_cnt += st.top().second;
                same_cnt = (st.top().second + 1);
                if (st.size() > 1) pair_cnt++;
                st.pop();
            } else {
                pair_cnt++;
            }
        }

        st.push({num, same_cnt});
    }
    cout << pair_cnt;
}

/**
 * 2 4 1 2 2 5 1
 * 24 41 42 12 22 42 45 25 25 51
 * 
 * -> 키가 큰 사람이 나타났을 때가 관건..
 * 
 * stact<pair<int, int>> 으로 저장??
 * (2, 1) (4, 1) -> ++
 * 현재 스택 = (4, 1)
 * 
 * push(1) -> ++
 * 현재 스택 = (4, 1), (1, 1)
 * 
 * push(2) -> ++ ++
 * -> top().second = 1이므로, ++
 * -> pop
 * -> top() = (4, 1), 4 != 2 이므로 ++
 * 현재 스택 = (4, 1), (2, 1)
 * 
 * push(2) -> ++ ++ (2인 사람이 두명)
 * cnt += top().second
 * (2, 1) 을 (2, 2)로 갱신
 * pop하지 않았으므로 (4가 가장 크니깐!!) ++
 * 현재 스택 = (4, 1), (2, 2)
 * 
 * push(5) -> ++ ++ ++ (max 갱신)
 * 큰 값이 들어왔다!
 * (2, 2) pop하고, 2만큼 증가
 * 1은 작으므로 이미 pop되어있음...
 * (4, 1) 보다도 크므로 1만큼 증가
 * 
 * -> 크지 않은 값이 들어오면 stack을 갱신
 */