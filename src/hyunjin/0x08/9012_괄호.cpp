#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    string str;
    while (n--) {
        cin >> str;

        stack<int> s;
        int flag = 0;
        for (auto c : str) {
            if (c == '(') s.push(c);
            else if (c == ')') {
                if (s.empty()) {
                    flag = 1;
                    break;
                }
                else s.pop();
            }
        }

        if (flag == 0 && s.empty()) cout << "YES\n";
        else cout << "NO\n";
    }
}
