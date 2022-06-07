#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second
int board[300][300];
int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, x, y, xx, yy;
        cin >> n;
        cin >> x >> y;
        cin >> xx >> yy;

        for (int i = 0; i < n; i++)
            fill(board[i], board[i] + n, -1);
        board[x][y] = 0;
        queue<pair<int, int> > q;
        q.push(make_pair(x, y));
        while (!q.empty())
        {
            pair<int, int> cur = q.front();
            q.pop();
            for (int dir = 0; dir < 8; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                    continue;
                if (board[nx][ny] >= 0)
                    continue;
                board[nx][ny] = board[cur.X][cur.Y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
        cout << board[xx][yy] << '\n';
    }
}