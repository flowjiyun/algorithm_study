#include <iostream>
#include <queue>
#include <utility>
#define X first
#define Y second
using namespace std;

int board[300][300];
int dist[300][300];
int dx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            fill(board[i], board[i] + n, 0);
            fill(dist[i], dist[i] + n, -1);
        }
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        queue<pair<int, int>> Q;
        Q.push({x, y});
        dist[x][y] = 0;
        while (!Q.empty())
        {
            pair<int, int> cur = Q.front();
            Q.pop();
            for (int dir = 0; dir < 8; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >=n || ny < 0 || ny >= n)
                    continue;
                if (dist[nx][ny] >= 0)
                    continue;
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                Q.push({nx, ny});
            }
        }
        cout << dist[a][b] << '\n';
    }
}