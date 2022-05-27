#include <iostream>
#include <stack>

using namespace std;
/*
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, top;
    int max = 100000001;
    stack<pair<int, int>> st;
    cin >> n;
    st.push({ max, 0 });
    for (int i = 1; i <= n; i++) {
        cin >> top;
        while (st.top().first < top) {
            st.pop();
        }
        cout << st.top().second << " ";
        st.push({top, i});
    }
    return 0;
}*/