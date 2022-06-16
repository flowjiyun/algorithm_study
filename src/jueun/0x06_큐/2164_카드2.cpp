#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<int> q;
    int n, cnt;

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }

    cnt = 1;
    while (!q.empty())
    {
        if (q.size() == 1)
        {
            cout << q.front();
            q.pop();
        }
        else
        {
            if (cnt % 2 == 0)
            {
                cnt = 0;
                q.push(q.front());
                q.pop();
            }
            else
            {
                q.pop();
            }
        }

        cnt++;
    }

    return 0;
}