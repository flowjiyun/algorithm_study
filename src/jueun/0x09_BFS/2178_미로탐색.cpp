#include <iostream>
#include <queue>
#include <utility>
#include <string>
using namespace std;

int n, m;
int arr[101][101];
int visited[101][101];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

string str;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> str;
        fill(visited[i], visited[i] + m, -1);
        for (int j = 0; j < m; j++)
            arr[i][j] = str[j] - '0';
    }

    queue<pair<int, int>> q;

    q.push(make_pair(0, 0));
    visited[0][0] = 0;

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
            if (visited[nx][ny] >= 0 || !arr[nx][ny])
                continue;
            visited[nx][ny] = visited[xx][yy] + 1;
            q.push(make_pair(nx, ny));
        }
    }

    cout << visited[n - 1][m - 1] + 1;
    return 0;
}
