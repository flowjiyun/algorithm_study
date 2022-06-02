#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    string str;
    int cnt = 0;
    while (n--) {
        cin >> str;

        stack<int> s;
        for(auto a : str) {
            if (s.empty() || s.top() != a)
                s.push(a);
            else 
                s.pop();
        }

        if (s.empty()) cnt++;
    }
    cout << cnt;
}
