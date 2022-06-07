#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

string board[1002];
int dist[1002][1002];
int fire[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> board[i];
    for (int i = 0; i < n; i++)
    {
        fill(dist[i], dist[i] + m, -1);
        fill(fire[i], fire[i] + m, -1);
    }
    queue<pair<int, int>> d;
    queue<pair<int, int>> f;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'J')
            {
                d.push({i, j});
                dist[i][j] = 0;
            }
            if (board[i][j] == 'F')
            {
                f.push({i, j});
                fire[i][j] = 0;
            }
        }
    }
    while (!f.empty())
    {
        pair<int, int> cur = f.front();
        f.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (fire[nx][ny] >= 0 || board[nx][ny] == '#')
                continue;
            fire[nx][ny] = fire[cur.X][cur.Y] + 1;
            f.push({nx, ny});
        }
    }
    while (!d.empty())
    {
        pair<int, int> cur = d.front();
        d.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            {
                cout << dist[cur.X][cur.Y] + 1;
                return (0);
            }
            if (dist[nx][ny] >= 0 || board[nx][ny] == '#')
                continue;
            if (fire[nx][ny] != -1 && fire[nx][ny] <= dist[cur.X][cur.Y] + 1)
                continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            d.push({nx, ny});
        }
    }
}