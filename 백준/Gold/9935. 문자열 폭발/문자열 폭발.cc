#include <bits/stdc++.h>
using namespace std;
int main() {
    stack<char> st;
    string a, boom;
    cin >> a >> boom;
    for (int i = 0; i < a.length(); i++) {
        st.push(a[i]);
        // top()이 마지막 문자이면서 stack에 쌓인 문자 수가 boom.length() 이상인 경우.
        if (st.top() == boom[boom.length()-1] && st.size() >= boom.length()) {
            string check;
            int tmp = boom.length();
            // 전부 넣으면서 pop
            for (int j = 0; j < tmp; j++) {
                check.push_back(st.top());
                st.pop();
            }
            reverse(check.begin(), check.end());
            // 뒤집고, 그게 boom과 다르면 다시 넣기.
            if (check != boom)
                for (int k = 0; k < check.length(); k++) st.push(check[k]);
            // 같으면 pop한 상태 유지.
        }
    }
    string ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    if (ans.empty()) cout << "FRULA";
    else cout << ans;
}
// insert() = O(N)...


/*
1차 폭발
mirkovnizC4
stack -> C4CC44
2차 폭발
mirkovniz
-> stack. 그냥 괄호 문자열인데요?

1차 폭발
12ab
2차 폭발
FRULA
-> !stack.empty()
*/