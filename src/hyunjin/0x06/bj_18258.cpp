#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    queue<int> q;
    int n;
    cin >> n;

    string order;
    int num;
    for (int i = 0; i < n; i++) {
        cin >> order;

        if (order == "push") {
            cin >> num;
            q.push(num);
        }
        else if (order == "pop") {
            if (q.empty()) cout << -1 << "\n";
            else {
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if (order == "size") cout << q.size() << "\n";
        else if (order == "empty") cout << q.empty() << "\n";
        else if (order == "front") {
            if (q.empty() == 1) cout << -1 << "\n";
            else cout << q.front() << "\n";
        }
        else if (order == "back") {
            if (q.empty() == 1) cout << -1 << "\n";
            else cout << q.back() << "\n";
        }
    }
}
