#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

#define X first
#define Y second
char board[101][101];
bool vis[100][100];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int bfs(int N)
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (vis[i][j])
                continue;
            count++;
            queue<pair<int, int> > q;
            q.push(make_pair(i, j));
            vis[i][j] = 1;

            while (!q.empty())
            {
                pair<int, int> cur = q.front();
                q.pop();
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                        continue;
                    if (vis[nx][ny] || board[i][j] != board[nx][ny])
                        continue;
                    vis[nx][ny] = 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    return count;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    int result1 = bfs(N);
    memset(vis, false, sizeof(vis));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 'G')
                board[i][j] = 'R';
        }
    }
    int result2 = bfs(N);
    cout << result1 << '\n'
         << result2;
}