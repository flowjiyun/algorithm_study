// 불
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string board[1002];
int dist_F[1002][1002];
int dist_S[1002][1002];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n, w, h;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int cnt = 0; cnt < n; cnt++)
    {
        queue<pair<int, int>> QF;
        queue<pair<int, int>> QS;
        cin >> w >> h;
        for (int i = 0; i < h; i++)
        {
            fill(dist_F[i], dist_F[i] + w, -1);
            fill(dist_S[i], dist_S[i] + w, -1);
        }

        /* make board & set 상근 위치, 불 위치 */
        for (int i = 0; i < h; i++)
        {
            cin >> board[i];
            for (int j = 0; j < w; j++)
            {
                if (board[i][j] == '*')
                {
                    QF.push({i, j});
                    dist_F[i][j] = 0;
                }
                else if (board[i][j] == '@')
                {
                    QS.push({i, j});
                    dist_S[i][j] = 0;
                }
            }
        }

        /* 시작점이 여러개일때 bfs + 시작점이 두 종류일 때(첫번째)*/
        while (!QF.empty())
        {
            auto cur = QF.front();
            QF.pop();
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                    continue;
                if (dist_F[nx][ny] >= 0 || board[nx][ny] == '#')
                    continue;
                dist_F[nx][ny] = dist_F[cur.X][cur.Y] + 1;
                QF.push({nx, ny});
            }
        }

        /* 시작점이 두종류일 때(두번째) */
        int flag = 0;
        while (!QS.empty() && !flag)
        {
            auto cur = QS.front();
            QS.pop();
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                {
                    cout << dist_S[cur.X][cur.Y] + 1 << '\n';
                    flag = 1;
                    break;
                }

                if (dist_S[nx][ny] >= 0 || board[nx][ny] == '#')
                    continue;
                if (dist_S[cur.X][cur.Y] + 1 >= dist_F[nx][ny] && dist_F[nx][ny] != -1)
                    continue;

                dist_S[nx][ny] = dist_S[cur.X][cur.Y] + 1;
                QS.push({nx, ny});
            }
        }
        if (flag == 0)
            cout << "IMPOSSIBLE\n";
    }
}
