#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int board[52][52];
bool vis[52][52];
int dx[4] = {1, 0, -1 ,0};
int dy[4] = {0, 1, 0, -1};
int t, m, n, k; // m은 열, n은 행
queue<pair<int, int>> Q;

void BFS(int x, int y)
{
    vis[x][y] = 1;
    Q.push({x, y});
    while(!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (board[nx][ny] != 1 || vis[nx][ny])
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

    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> m >> n >> k;
        for (int i = 0; i < k; i++)
        {
            cin >> x >> y; // x는 열(m) y는 행(n)
            board[y][x] = 1;
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] != 1 || vis[i][j])
                    continue;
                cnt++;
                BFS(i, j);
            }
        }
        cout << cnt << '\n';
        for (int i = 0; i < n; i++)
        {
            fill(board[i], board[i] + m, 0);
            fill(vis[i], vis[i] + m, 0);
        }
    }
}
