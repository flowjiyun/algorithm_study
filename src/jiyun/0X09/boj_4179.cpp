#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

string board[1000];
int fire[1000][1000];
int person[1000][1000];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int, int>> F;
    queue<pair<int, int>> P;
    int r;
    int c;
    cin >> r >> c;
    for (int i = 0; i < r; i++)
        cin >> board[i];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (board[i][j] == '#' || board[i][j] == '.')
            {
                fire[i][j] = -1;
                person[i][j] = -1;
                continue;
            }
            else if (board[i][j] == 'F')
                F.push({i, j});
            else
                P.push({i, j});
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
            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                continue;
            if (fire[nx][ny] >= 0 || board[nx][ny] == '#')
                continue;
            fire[nx][ny] = fire[cur.X][cur.Y] + 1;
            F.push({nx, ny});
        }
    }
    while (!P.empty())
    {
        pair<int, int> cur = P.front();
        P.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
            {
                cout << person[cur.X][cur.Y] + 1;
                return (0);
            }
            if (person[nx][ny] >= 0 || board[nx][ny] == '#')
                continue;
            if (fire[nx][ny] != -1 && fire[nx][ny] <= person[cur.X][cur.Y] + 1)
                continue;
            person[nx][ny] = person[cur.X][cur.Y] + 1;
            P.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE";
    return (0);
}