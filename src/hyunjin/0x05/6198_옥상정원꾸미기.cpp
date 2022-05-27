#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> s;
    int n;
    cin >> n;

    int tar;
    long long cnt = 0;
    for(int i = 0; i < n; i++) {
        cin >> tar;
        
        while (!s.empty() && s.top() <= tar)
            s.pop();
        cnt += s.size();
        s.push(tar);
    }

    cout << cnt;
}
