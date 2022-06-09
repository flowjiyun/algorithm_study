#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

char board[30][30][30];
int dist[30][30][30];
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int L, R, C;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    

    while(true)
    {
        cin >> L >> R >> C;

        if (L == 0 && R == 0 && C == 0)
            break;
        fill((int *)dist, (int *)(dist + 30), 0);

        queue<tuple<int, int, int>> Q;
        for (int k = 0; k < L; k++)
            for (int i = 0; i < R; i++)
                for (int j = 0; j < C; j++)
                {
                    cin >> board[k][i][j];
                    if (board[k][i][j] == 'S')
                        Q.push({k, i, j});
                }

        int flag = 1;
        while (!Q.empty())
        {
            tuple<int, int, int> cur = Q.front();
            Q.pop();
            int cur_z, cur_x, cur_y;
            tie(cur_z, cur_x, cur_y) = cur;
            for (int dir = 0; dir < 6; dir++)
            {
                int nx = cur_x + dx[dir];
                int ny = cur_y + dy[dir];
                int nz = cur_z + dz[dir];
                if (nx < 0 || ny < 0 || nz < 0 || nx >= R || ny >= C || nz >= L)
                    continue;
                if (dist[nz][nx][ny] != 0 || board[nz][nx][ny] == '#')
                    continue;
                dist[nz][nx][ny] = dist[cur_z][cur_x][cur_y] + 1;
                if (board[nz][nx][ny] == 'E')
                {
                    cout << "Escaped in " << dist[nz][nx][ny] << " minute(s).\n";
                    flag = 0;
                }
                Q.push({nz, nx, ny});
            }
        }
        if (flag)
            cout << "Trapped!\n";
    }
}