#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

int n, res;
int arr[101][101];
int visited[101][101];

vector<pair<int, int>> v;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void cal()
{
    int tmp = 0;

    for (int i = 0; i < v.size(); i++)
    {
        int x = v[i].first;
        int y = v[i].second;

        for (int j = i + 1; j < v.size(); j++)
        {
            int xx = v[j].first;
            int yy = v[j].second;

            if (arr[x][y] > 0 && arr[xx][yy] > 0 && arr[xx][yy] != arr[x][y])
            {
                tmp = abs(yy - y) + abs(xx - x) - 1;
                if (res > tmp)
                    res = tmp;
            }
        }
    }
}

void check_land(int x, int y, int idx)
{
    queue<pair<int, int>> q;

    q.push(make_pair(x, y));

    while (!q.empty())
    {
        int xx = q.front().first;
        int yy = q.front().second;

        arr[xx][yy] = idx;

        q.pop();

        bool edge = false;

        for (int i = 0; i < 4; i++)
        {

            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                continue;

            if (visited[nx][ny] == true)
                continue;

            if (arr[nx][ny] < 0)
            {
                arr[nx][ny] = idx;
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }

            else if (arr[nx][ny] == 0)
                edge = true;
        }

        if (edge)
        {
            v.push_back({xx, yy});
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            visited[i][j] = false;
            if (arr[i][j] == 1)
                arr[i][j] = -1;
        }
    }

    int check = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == -1)
            {
                check_land(i, j, check);
                check++;
            }
        }
    }

    res = 2147483647;
    cal();

    cout << res;

    return 0;
}
