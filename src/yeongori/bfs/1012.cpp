// 유기농 배추
#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int board[52][52];
bool vis[52][52];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int M, N;

void bfs(int &j, int &k)
{
    queue<pair<int, int>> Q;
    Q.push({j, k});
    vis[j][k] = 1;
    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            if (board[nx][ny] == 0 || vis[nx][ny])
                continue;

            Q.push({nx, ny});
            vis[nx][ny] = 1;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T, K, x, y;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> M >> N >> K;
        for (int j = 0; j < K; j++)
        {
            cin >> x >> y;
            board[y][x] = 1;
        }
        int cnt = 0;
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                if (vis[j][k] || board[j][k] == 0)
                    continue;
                bfs(j, k);
                cnt++;
            }
        }
        for (int j = 0; j < N; j++)
        {
            fill(board[j], board[j] + M, 0);
            fill(vis[j], vis[j] + M, 0);
        }
        cout << cnt << '\n';
    }
}