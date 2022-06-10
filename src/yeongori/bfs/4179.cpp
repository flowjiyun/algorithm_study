// 불!
#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
int dist_2[1002][1002];
int dist_1[1002][1002];

string board[1002];
int r, c;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

queue<pair<int, int>> Q2;
queue<pair<int, int>> Q1;

int main(void)
{
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        fill(dist_2[i], dist_2[i] + c, -1);
        fill(dist_1[i], dist_1[i] + c, -1);
    }

    for (int i = 0; i < r; i++)
    {
        cin >> board[i];
        for (int j = 0; j < c; j++)
        {
            if (board[i][j] == 'F')
            {
                Q1.push({i, j});
                dist_1[i][j] = 0;
            }
            else if (board[i][j] == 'J')
            {
                Q2.push({i, j});
                dist_2[i][j] = 0;
            }
        }
    }

    while (!Q1.empty())
    {
        auto cur = Q1.front();
        Q1.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                continue;
            if (dist_1[nx][ny] >= 0 || board[nx][ny] == '#')
                continue;
            dist_1[nx][ny] = dist_1[cur.X][cur.Y] + 1;
            Q1.push({nx, ny});
        }
    }

    while (!Q2.empty())
    {
        auto cur = Q2.front();
        Q2.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
            {
                cout << dist_2[cur.X][cur.Y] + 1;
                return 0;
            }
            if (dist_2[nx][ny] >= 0 || board[nx][ny] == '#')
                continue;

            /*
            dist_1[nx][ny] != -1 이조건은 왜 필요한거지
            */
            if (dist_2[cur.X][cur.Y] + 1 >= dist_1[nx][ny] && dist_1[nx][ny] != -1)
                continue;

            dist_2[nx][ny] = dist_2[cur.X][cur.Y] + 1;
            Q2.push({nx, ny});
        }
    }

    cout << "IMPOSSIBLE\n";
}