#include <iostream>
#include <queue>
#include <string>
#include <tuple>

using namespace std;

string board[1000];
int vis[2][1000][1000];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<tuple<int, int, int>> Q;
    int n;
    int m;
    int state = 0;
    int valid = 0;
    cin >> n >> m;
    if (n == 1 && m == 1)
    {
        cout << 1;
        return (0);
    }
    for (int i = 0; i < n; i++)
        cin >> board[i];
    Q.push({0, 0, 0});
    while (!Q.empty())
    {
        tuple<int, int, int> cur = Q.front();
        Q.pop();
        int wall, x, y;
        tie(wall, x, y) = cur;
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (nx == n - 1 && ny == m - 1)
            {
                cout << vis[wall][x][y] + 2;
                return (0);
            }
            if (vis[wall][nx][ny])
                continue;
            if (board[nx][ny] == '0')
            {
                vis[wall][nx][ny] = vis[wall][x][y] + 1;
                Q.push({wall, nx, ny});
            }
            else if (board[nx][ny] == '1')
            {
                if (wall == 1)
                    continue;
                vis[wall + 1][nx][ny] = vis[wall][x][y] + 1;
                Q.push({wall + 1, nx, ny});
            } 
        }
    }
    cout << -1;
    return (0);
}

