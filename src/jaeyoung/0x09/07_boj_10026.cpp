#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

string board[102];
bool vis[102][102];
int n;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> Q;

void BFS(int x, int y)
{
    vis[x][y] = 1;
    Q.push({x, y});
    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if (board[nx][ny] != board[cur.X][cur.Y] || vis[nx][ny])
                continue;
            vis[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }
}

int RGB(void)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if (vis[i][j] != 1)
            {
                BFS(i, j);
                cnt++;
            }
        }
    }
    return (cnt);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt;
    cin >> n;
    for (int i = 0; i < n; i++)
       cin >> board[i];
    cnt = RGB();
    cout << cnt << ' ';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 'R')
                board[i][j] = 'G';
        }
    }
    for (int i = 0; i < n; i++)
        fill(vis[i], vis[i] + n, 0);
    cnt = RGB();
    cout << cnt;
}