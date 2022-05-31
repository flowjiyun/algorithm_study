#include <iostream>
#include <deque>
using namespace std;

deque<int> dq;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, i, cnt = 0, tmp, idx, value;

    cin >> n >> m;
    i = 1;
    while (i <= n)
        dq.push_back(i++);
    while (m--)
    {
        cin >> value;
        idx = 1;
        auto cur = dq.begin();
        while (*cur != value)
        {
            idx++;
            cur++;
        }
        if (idx < ((dq.size() + 1) / 2 + 1))
        {
            while (value != dq.front())
            {
                tmp = dq.front();
                dq.pop_front();
                dq.push_back(tmp);
                cnt++;
            }
            dq.pop_front();
        }
        else
        {
            while (value != dq.back())
            {
                tmp = dq.back();
                dq.pop_back();
                dq.push_front(tmp);
                cnt++;
            }
            dq.pop_back();
            cnt++;
        }
    }
    cout << cnt;
}
