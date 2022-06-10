// 토마토
#include <bits/stdc++.h>

using namespace std;

int board[102][102][102];
int dist[102][102][102];
int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

int m, n, h;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int flag = 0;
    int x, y, z;
    cin >> m >> n >> h;
    queue<tuple<int, int, int>> Q;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                cin >> board[j][k][i];
                if (board[j][k][i] == 1)
                    Q.push(make_tuple(j, k, i));
                else if (board[j][k][i] == 0)
                {
                    dist[j][k][i] = -1;
                    flag = 1;
                }
                /*
                M, N을 잘 이해하지 못해서 한참 헤맸음
                M은 가로 칸의 수 이다. 2번째 입력 줄부터는 가로줄에 들어있는 토마토들의 상태를 M개의 정수로 표현했는데
                그렇다면 가로와 높이는 가만히 둔채 상자의 세로를 늘려가면서 입력을 받게 된다.
                이러한 관계를 생각치 않고 무조건 그냥 i j k 순으로 입력을 받앗던게 화근이였다.
                */
                // cin >> board[i][j][k];
                // if (board[i][j][k] == 1)
                //     Q.push(make_tuple(i, j, k));
                // else if (board[i][j][k] == 0)
                // {
                //     dist[i][j][k] = -1;
                //     flag = 1;
                // }
            }
        }
    }

    while (!Q.empty())
    {
        tie(x, y, z) = Q.front();
        Q.pop();
        for (int dir = 0; dir < 6; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nz = z + dz[dir];
            if (nx < 0 || ny < 0 || nz < 0 || nx >= n || ny >= m || nz >= h)
                continue;
            if (dist[nx][ny][nz] >= 0)
                continue;
            dist[nx][ny][nz] = dist[x][y][z] + 1;
            Q.push(make_tuple(nx, ny, nz));
        }
    }

    /*
    여기서도 마찬가지로 M과 N의 관계를 깊게 생각하지 않아서
    i j k 순으로 돌리는 오류를 범했음
    */
    int ans = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (dist[j][k][i] < 0)
                    flag = -1;
                ans = max(ans, dist[j][k][i]);
            }
        }
    }

    if (flag == 0)
        cout << 0;
    else if (flag == -1)
        cout << -1;
    else
        cout << ans;
    return 0;
}