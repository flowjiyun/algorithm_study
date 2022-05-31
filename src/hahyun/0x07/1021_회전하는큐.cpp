#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, index, cnt = 0;
    cin >> N >> M;
    deque<int> dq;
    for (int i = 1; i <= N; i++)
    {
        dq.push_back(i);
    }
    while (M--)
    {
        int x;
        cin >> x;
        for (int i = 0; i < dq.size(); i++)
        {
            if (dq[i] == x)
            {
                index = i;
                break;
            }
        }

        if (index < dq.size() - index)
        {
            while (1)
            {
                if (dq.front() == x)
                {
                    dq.pop_front();
                    break;
                }
                dq.push_back(dq.front());
                dq.pop_front();
                cnt++;
            }
        }
        else
        {
            while (1)
            {
                if (dq.front() == x)
                {
                    dq.pop_front();
                    break;
                }
                dq.push_front(dq.back());
                dq.pop_back();
                cnt++;
            }
        }
    }
    cout << cnt;
}