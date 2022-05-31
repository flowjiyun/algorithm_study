#include <bits/stdc++.h>
using namespace std;

int main()
{
    deque<int> d;
    int n;
    cin >> n;

    string order;
    int num;
    for (int i = 0; i < n; i++) {
        cin >> order;

        if (order == "push_front") {
            cin >> num;
            d.push_front(num);
        }
        else if (order == "push_back") {
            cin >> num;
            d.push_back(num);
        }
        else if (order == "pop_front") {
            if (d.empty()) cout << -1 << "\n";
            else {
                cout << d.front() << "\n";
                d.pop_front();
            }
        }
        else if (order == "pop_back") {
            if (d.empty()) cout << -1 << "\n";
            else {
                cout << d.back() << "\n";
                d.pop_back();
            }
        }
        else if (order == "size") cout << d.size() << "\n";
        else if (order == "empty") cout << d.empty() << "\n";
        else if (order == "front") {
            if (d.empty()) cout << -1 << "\n";
            else cout << d.front() << "\n";
        }
        else if (order == "back") {
            if (d.empty()) cout << -1 << "\n";
            else cout << d.back() << "\n";
        }
    }
}
