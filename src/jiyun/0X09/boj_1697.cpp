#include <bits/stdc++.h>

using namespace std;
int board[100001];
int vis[100001];
int a[3] = {1, -1, 0};
int b[3] = {1, 1, 2};
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<int> Q;
    int n;
    int k;
    cin >> n >> k;
    board[n] = 1;
    board[k] = 2;
    for (int i = 0; i < 100001; i++)
        vis[i] = -1;
    vis[n] = 0;
    Q.push(n);
    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 3; dir++)
        {
            int nx = b[dir] * cur + a[dir];
            if (nx < 0 || nx > 100000)
                continue;
            if (vis[nx] >= 0)
                continue;
            if (board[nx] == 2)
            {
                cout << vis[cur] + 1;
                return (0);
            }
            vis[nx] = vis[cur] + 1;
            Q.push(nx);
        }
    }
    cout << 0;
    return (0);
}