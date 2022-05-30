// 회전하는 큐
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    deque<int> dq1, dq2;
    int n, m, p, cnt1, cnt2, total = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        dq1.push_back(i);
        dq2.push_back(i);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> p;
        if (dq1.front() == p)
        {
            dq1.pop_front();
            dq2.pop_front();
        }
        else
        {
            for (cnt1 = 0; dq1.front() != p; cnt1++)
            {
                dq1.push_front(dq1.back());
                dq1.pop_back();
            }
            dq1.pop_front();

            for (cnt2 = 0; dq2.front() != p; cnt2++)
            {
                dq2.push_back(dq2.front());
                dq2.pop_front();
            }
            dq2.pop_front();

            if (cnt1 > cnt2)
                total += cnt2;
            else
                total += cnt1;
        }
    }
    cout << total << '\n';
}