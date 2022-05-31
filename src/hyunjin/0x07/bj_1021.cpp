#include <bits/stdc++.h>
using namespace std;

int main()
{
    deque<int> d;
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        d.push_back(i);
    }

    int num, now;
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        cin >> num;

        now = 0;
        while (d[now] != num) now++;

        if (now <= d.size() / 2) {
            while(d.front() != num) {
                d.push_back(d.front());
                d.pop_front();
                cnt++;
            }
        }
        else {
            while (d.front() != num) {
                d.push_front(d.back());
                d.pop_back();
                cnt++;
            }
        }

        d.pop_front();
    }

    cout << cnt;
}
