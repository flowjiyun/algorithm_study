#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[500][500] = {};
bool vis[500][500];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int m;
    int cnt = 0;
    int max = 0;
    queue<pair<int, int>> Q;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == 1 || board[i][j] != 1)
                continue; 
            vis[i][j] = 1;
            cnt++;   
            Q.push({i,j});
            int size = 1;
            while (!Q.empty())
            {
                pair<int, int> cur = Q.front();
                Q.pop();
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue;
                    if (vis[nx][ny] == 1 || board[nx][ny] != 1)
                        continue;
                    vis[nx][ny] = 1;
                    size++;
                    Q.push({nx, ny});
                }
            }
            if (max < size)
                max = size;
        }
    }
    cout << cnt << '\n' << max;
    return (0);
}
