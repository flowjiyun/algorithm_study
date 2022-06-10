#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[1001][1001];
int visited[1001][1001][2];
int n, m;
int bfs(int i, int j)
{
    queue <tuple<int, int, int>> q;
    q.push({i, j, 0});
    visited[i][j][0] = 1;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int x, y, w;
        tie(x, y, w) = cur;
        if (x == n - 1 && y == m - 1)
            return (visited[x][y][w]);
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (visited[nx][ny][w])
                continue;
            if (!board[nx][ny])
            {
                visited[nx][ny][w] = visited[x][y][w] + 1;
                q.push({nx, ny, w});
            }
            if (!w && board[nx][ny])
            {
                visited[nx][ny][1] = visited[x][y][0] + 1;
                q.push({nx, ny, 1});
            }
        }
    }
    return (-1);
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            scanf("%1d", &board[i][j]);     //To get the input value of int by a single letter.

    }
    cout << bfs(0,0);
}