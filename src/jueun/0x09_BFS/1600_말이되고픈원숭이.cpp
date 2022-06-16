#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int k, n, m;
int arr[201][201];
bool visited[201][201][31];

queue<pair<pair<int, int>, pair<int, int>>> q;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int cdx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int cdy[8] = {-2, -1, 1, 2, -2, -1, 1, 2};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k;

    cin >> m >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    }

    q.push(make_pair(make_pair(0, 0), make_pair(0, 0)));
    visited[0][0][0] = true;

    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second.first;
        int jump = q.front().second.second;

        q.pop();

        if (x == n - 1 && y == m - 1)
        {
            cout << cnt;
            return 0;
        }

        if (jump < k)
        {
            for (int i = 0; i < 8; i++)
            {
                int nx = x + cdx[i];
                int ny = y + cdy[i];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;
                if (arr[nx][ny] == 1 || visited[nx][ny][jump + 1] == true)
                    continue;

                visited[nx][ny][jump + 1] = true;
                q.push(make_pair(make_pair(nx, ny), make_pair(cnt + 1, jump + 1)));
            }
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (arr[nx][ny] == 1 || visited[nx][ny][jump] == true)
                continue;

            visited[nx][ny][jump] = true;
            q.push(make_pair(make_pair(nx, ny), make_pair(cnt + 1, jump)));
        }
    }

    cout << -1;
    return 0;
}
