#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#define X first
#define Y second
using namespace std;

int board[100][100];
int vis[100][100];
int dist[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n;
int bridge = 1000001;

void island()
{
    int idx = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vis[i][j] || board[i][j] == 0)
                continue;
            queue<pair<int, int>> Q;
            Q.push({i, j});
            vis[i][j] = 1;
            while(!Q.empty())
            {
                pair<int, int> cur = Q.front();
                Q.pop();
                board[cur.X][cur.Y] = idx;
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                        continue;
                    if (vis[nx][ny] || board[nx][ny] == 0)
                        continue;
                    vis[nx][ny] = 1;
                    Q.push({nx,ny});
                }
            }
            idx++;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    island();
    fill ((int *)dist, (int *)(dist + n), -1);

    queue<pair<int, int>> Q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] != 0)
            {
                dist[i][j] = 0;
                Q.push({i, j});
            }
        }
    }
    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        if (bridge < dist[cur.X][cur.Y])
            break;
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if (board[nx][ny] == board[cur.X][cur.Y])
                continue;
            if (board[nx][ny] != 0)
            {
                bridge = min(bridge, dist[nx][ny] + dist[cur.X][cur.Y]);
            }
            else
            {
                board[nx][ny] = board[cur.X][cur.Y];
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                Q.push({nx, ny});
            }
        }
    }
    cout << bridge;
}
