#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int t, n, x, y, f_x, f_y;

int arr[301][301];
int visited[301][301];

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {-2, -1, 1, 2, -2, -1, 1, 2};

void bfs(int i, int j)
{
    visited[i][j] = 0;

    queue<pair<int, int>> q;

    q.push(make_pair(i, j));

    while (!q.empty())
    {
        int xx = q.front().first;
        int yy = q.front().second;

        q.pop();

        if (xx == f_x && yy == f_y)
        {
            cout << visited[xx][yy] << "\n";
            return;
        }

        for (int p = 0; p < 8; p++)
        {
            int nx = xx + dx[p];
            int ny = yy + dy[p];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                continue;
            if (visited[nx][ny] >= 0)
                continue;
            visited[nx][ny] = visited[xx][yy] + 1;
            q.push(make_pair(nx, ny));
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;
        cin >> x >> y;
        cin >> f_x >> f_y;

        for (int i = 0; i < n; i++)
        {
            fill(arr[i], arr[i] + n, -1);
            fill(visited[i], visited[i] + n, -1);
        }

        arr[x][y] = 1;
        bfs(x, y);
    }
    return 0;
}
