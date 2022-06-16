#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n, m, res;
int arr[1001][1001];
int visited[1001][1001];
queue<pair<int, int>> q;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            visited[i][j] = -1;
            if (arr[i][j] == 1)
            {
                q.push(make_pair(i, j));
                visited[i][j]++;
            }
        }
    }

    while (!q.empty())
    {
        int xx = q.front().first;
        int yy = q.front().second;

        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if (nx < 0 || ny < 0 || n <= nx || m <= ny)
                continue;
            if (visited[nx][ny] >= 0 || arr[nx][ny] != 0)
                continue;
            visited[nx][ny] = visited[xx][yy] + 1;
            q.push(make_pair(nx, ny));
        }
    }

    res = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] == -1 && arr[i][j] == 0)
            {
                cout << -1;
                return 0;
            }
            if (visited[i][j] > res)
                res = visited[i][j];
        }
    }
    cout << res;
    return 0;
}
