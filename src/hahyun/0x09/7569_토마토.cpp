#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int board[100][100][100];
int vis[100][100][100];
int dx[] = {0, 0, 1, -1, 0, 0};
int dy[] = {1, -1, 0, 0, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int M, N, H;
    cin >> M >> N >> H;
    queue<tuple<int, int, int> > q;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                int tmp;
                cin >> tmp;
                board[i][j][k] = tmp;
                if (tmp == 1)
                    q.push(make_tuple(j, k, i));
                if (tmp == 0)
                    vis[j][k][i] = -1;
            }
        }
    }
    while (!q.empty())
    {
        tuple<int, int, int> cur = q.front();
        q.pop();
        int curX, curY, curZ;
        tie(curX, curY, curZ) = cur;
        for (int dir = 0; dir < 6; dir++)
        {
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            int nz = curZ + dz[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H)
                continue;
            if (vis[nx][ny][nz] >= 0)
                continue;
            vis[nx][ny][ny] = vis[curX][curY][curZ] + 1;
            q.push(make_tuple(nx, ny, nz));
        }
    }
    int result = 0;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                if (vis[j][k][i] == -1)
                {
                    cout << -1 << '\n';
                    return 0;
                }
                result = max(result, vis[j][k][i]);
            }
        }
    }
    cout << result << '\n';
}