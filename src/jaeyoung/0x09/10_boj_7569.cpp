#include <iostream>
#include <tuple>
#include <queue>
#include <algorithm>
using namespace std;

int board[102][102][102];
int dist[102][102][102];
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int m, n, h; // m은 열, n은 행
queue <tuple<int, int, int>> Q;

void ft_bfs(void)
{
    while (!Q.empty())
    {
        tuple<int, int, int> cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 6; dir++)
        {
            int nx = get<0>(cur) + dx[dir];
            int ny = get<1>(cur) + dy[dir];
            int nz = get<2>(cur) + dz[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h)
                continue;
            if (dist[nx][ny][nz] >= 0)
                continue;
            dist[nx][ny][nz] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            Q.push({nx, ny, nz});
        }
    }
}

int ft_mx()
{
    int res = 0;
    for (int k = 0; k < h; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (dist[i][j][k] == -1)
                    return (-1);
                else
                    res = max(res, dist[i][j][k]);
            }
        }
    }
    return (res);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> h;
    for (int k = 0; k < h; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> board[i][j][k];
                if (board[i][j][k] == 1)
                    Q.push({i, j, k});
                if (board[i][j][k] == 0)
                    dist[i][j][k] = -1;
            }
        }
    }
    ft_bfs();
    int mx;
    mx = ft_mx();
    if (mx != -1)
        cout << mx;
    else
        cout << -1;
}
