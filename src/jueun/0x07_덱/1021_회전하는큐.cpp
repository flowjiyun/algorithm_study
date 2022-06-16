#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<int> d;
    int n, m, k, cnt, idx;

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        d.push_back(i);

    cnt = 0;
    idx = 0;

    while (m--)
    {
        cin >> k;

        for (int i = 0; i < d.size(); i++)
        {
            if (d[i] == k)
            {
                idx = i;
                break;
            }
        }

        if (idx < d.size() - idx)
        {
            while (1)
            {
                if (d.front() == k)
                {
                    d.pop_front();
                    break;
                }
                cnt++;
                d.push_back(d.front());
                d.pop_front();
            }
        }

        else
        {
            while (1)
            {
                if (d.front() == k)
                {
                    d.pop_front();
                    break;
                }
                cnt++;
                d.push_front(d.back());
                d.pop_back();
            }
        }
    }

    cout << cnt;

    return 0;
}