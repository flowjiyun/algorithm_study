#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int, int>> Q;
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        int M;
        int K;
        int board[51][51] = {};
        int vis[51][51] = {};
        cin >> M >> N >> K;
        while (K--)
        {
            int X;
            int Y;
            cin >> X >> Y;
            board[Y][X] = 1;
        }
        int ans = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (vis[i][j] != 0 || board[i][j] != 1)
                    continue;
                vis[i][j] = 1;
                ans++;
                Q.push({i, j});
                while (!Q.empty())
                {
                    pair<int, int> cur = Q.front();
                    Q.pop();
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                            continue;
                        if (vis[nx][ny] != 0 || board[nx][ny] != 1)
                            continue;
                        vis[nx][ny] = 1;
                        Q.push({nx, ny}); 
                    }
                }

            }
        }
        cout << ans << '\n';
    }
    return (0);
}