#include <iostream>
#include <queue>
#include <utility>
#include <string>
#define X first
#define Y second
using namespace std;

string board[1002];
int fire[1002][1002];
int dist[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        queue<pair<int, int>> F = {};
        queue<pair<int, int>> D = {};
        int m, n;
        cin >> m >> n; // m은 열, n은 행
        for (int i = 0; i < n; i++)
        {
            cin >> board[i];
            fill(fire[i], fire[i] + m, -1);
            fill(dist[i], dist[i] + m, -1);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == '*')
                {
                    F.push({i, j});
                    fire[i][j] = 0;
                }
                if (board[i][j] == '@')
                {
                    D.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        while (!F.empty())
        {
            pair<int, int> cur = F.front();
            F.pop();
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;
                if (fire[nx][ny] != -1 || board[nx][ny] == '#')
                    continue;
                fire[nx][ny] = fire[cur.X][cur.Y] + 1;
                F.push({nx, ny});
            }
        }
        int flag = 1;
        while (!D.empty() && flag)
        {
            pair<int, int> cur = D.front();
            D.pop();
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                {
                    cout << dist[cur.X][cur.Y] + 1 << '\n';
                    flag = 0;
                    break;
                }
                if (dist[nx][ny] >= 0 || board[nx][ny] == '#')
                    continue;
                if (fire[nx][ny] != -1 && dist[cur.X][cur.Y] + 1 >= fire[nx][ny])
                    continue;
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                D.push({nx, ny});
            }
        }
        if (flag)
            cout << "IMPOSSIBLE\n";
    }
}
