#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

char board[1000][1000];
int dist[1000][1000][2];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
queue<tuple<int, int, int>> Q;

int ft_bfs()
{
    Q.push({0, 0, 0});
    dist[0][0][0] = 1;
    while (!Q.empty())
    {
        tuple<int, int, int> cur = Q.front();
        Q.pop();
        int cur_x, cur_y, destroy;
        tie(cur_x, cur_y, destroy) = cur;
        if (cur_x == n - 1 && cur_y == m - 1)
            return (dist[cur_x][cur_y][destroy]);
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur_x + dx[dir];
            int ny = cur_y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (dist[nx][ny][destroy] == 0 && board[nx][ny] == '0')
            {
                dist[nx][ny][destroy] = dist[cur_x][cur_y][destroy] + 1;
                Q.push({nx, ny, destroy});
            }
            if (dist[nx][ny][destroy] == 0 && board[nx][ny] == '1' && destroy == 0)
            {
                 dist[nx][ny][1] = dist[cur_x][cur_y][destroy] + 1;
                 Q.push({nx, ny, 1});
            }
        }
    }
    return (-1);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    }

    cout << ft_bfs();
}