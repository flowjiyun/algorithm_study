#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

#define X first
#define Y second
int board[51][51] = {
    0,
};
bool vis[51][51];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        int M, N, K;
        cin >> M >> N >> K;
        while (K--)
        {
            int x, y;
            cin >> x >> y;
            board[y][x] = 1;
        }

        int num = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (board[i][j] != 1 || vis[i][j])
                    continue;
                num++;
                queue<pair<int, int> > q;
                vis[i][j] = 1;
                q.push(make_pair(i, j));

                while (!q.empty())
                {
                    pair<int, int> cur = q.front();
                    q.pop();

                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                            continue;
                        if (vis[nx][ny] || board[nx][ny] != 1)
                            continue;
                        vis[nx][ny] = 1;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }
        cout << num << '\n';
        memset(board, false, sizeof(board));
        memset(vis, false, sizeof(vis));
    }
}