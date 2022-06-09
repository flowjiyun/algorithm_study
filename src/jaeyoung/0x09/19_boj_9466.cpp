#include <iostream>
#include <queue>
using namespace std;

int board[100002];
int vis[100002];
int t, n;
queue<int> Q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> board[i];
        for (int i = 1; i <= n; i++)
            vis[board[i]]++;
        for (int i = 1; i <=n; i++)
        {
            if (vis[i] == 0)
                Q.push(i);
        }
        int cnt = 0;
        while (!Q.empty())
        {
            cnt++;
            int cur = Q.front();
            Q.pop();
            vis[board[cur]]--;
            if (vis[board[cur]] == 0)
                Q.push(board[cur]);
        }
        cout << cnt << '\n';
        for (int i = 1; i <= n; i++)
            vis[i] = 0;
    }
}