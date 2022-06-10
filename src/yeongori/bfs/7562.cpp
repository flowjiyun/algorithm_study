// 나이트의 이동
#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int n, len, pos_x, pos_y, des_x, des_y;
int board[302][302];
int dx[8] = {-1, -1, 1, 1, -2, -2, 2, 2};
int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
int main(void)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        queue<pair<int, int>> Q;
        cin >> len;
        int dist[len][len];
        for (int j = 0; j < len; j++)
            fill(dist[j], dist[j] + len, -1);
        cin >> pos_x >> pos_y;
        cin >> des_x >> des_y;

        Q.push({pos_x, pos_y});
        dist[pos_x][pos_y] = 0;

        while (!Q.empty())
        {
            auto cur = Q.front();
            Q.pop();
            for (int dir = 0; dir < 8; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if (nx < 0 || nx >= len || ny < 0 || ny >= len)
                    continue;
                if (dist[nx][ny] >= 0)
                    continue;

                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                Q.push({nx, ny});
            }
        }
        cout << dist[des_x][des_y] << '\n';
    }
}