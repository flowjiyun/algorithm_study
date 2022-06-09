#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#define X first
#define Y second
using namespace std;

int board[300][300];
int vis[300][300];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;

void ice_bfs(int i, int j)
{
    queue<pair<int, int>> Q;
    Q.push({i, j});
    vis[i][j] = 1;
    while(!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (vis[nx][ny] || board[nx][ny] == 0)
                continue;
            vis[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    int year = 0;
    while (true)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j] || board[i][j] == 0)
                    continue;
                cnt++;
                ice_bfs(i, j);
            }
        }
        if (cnt == 0 || cnt >= 2)
        {
            cout << (cnt == 0 ? 0 : year);
            return (0);
        }
        fill((int *)vis, (int *)(vis + n), 0);
        year++;
        int sea[300][300] = {0};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 0)
                    continue;
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                        continue;
                    if (board[nx][ny] == 0)
                        sea[i][j]++;
                }
            }
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                board[i][j] = max(0, board[i][j] - sea[i][j]);
    }
}