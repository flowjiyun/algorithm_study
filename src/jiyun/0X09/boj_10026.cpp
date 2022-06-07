#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

string board[100];
int vis[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N;

void bfs(int i, int j)
{
    queue<pair<int, int>> Q;
    vis[i][j] = 1;
    Q.push({i, j});
    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            if (vis[nx][ny] != 0 || board[i][j] != board[nx][ny])
                continue;
            vis[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }
}

int cnt()
{
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (vis[i][j] != 0)
                continue;
            ans++;
            bfs(i, j);
        }
    }
    return (ans);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> board[i];

    int ans1 = cnt();
    cout << ans1 << ' ';

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            vis[i][j] = 0;
            if (board[i][j] == 'G')
                board[i][j] = 'R';
        }
    }

    int ans2 = cnt();
    cout << ans2;
    return (0);
}