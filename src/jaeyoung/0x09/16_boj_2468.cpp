#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#define X first
#define Y second
using namespace std;

int area[100][100];
int vis[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n;
int high = 0, low = 100;
int mx;

void ft_bfs(int i, int j, int k)
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
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if (vis[nx][ny] || area[nx][ny] <= k)
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

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> area[i][j];
            high = max(high, area[i][j]);
            low = min(low, area[i][j]);
        }
    }
    for (int k = low - 1; k < high; k++)
    {
        int num = 0;
        for (int i = 0; i < n; i++)
        {
            fill(vis[i], vis[i] + n, 0);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (area[i][j] > k && vis[i][j] != 1)
                {
                    num++;
                    ft_bfs(i, j, k);
                }
            }
        }
        mx = max(mx, num);
    }
    cout << mx;
}