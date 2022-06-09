#include <iostream>

using namespace std;

int n, m, cnt, year, ice;
int arr[301][301];
bool visited[301][301];

bool check = true;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void melt(int x, int y)
{
    int water = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
            continue;

        if (arr[nx][ny] == 0)
            water++;
    }

    arr[x][y] -= water;
    if (arr[x][y] == 0)
        arr[x][y] = -1;
}

void dfs(int x, int y)
{

    visited[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (arr[nx][ny] < 0)
            arr[nx][ny] = 0;
        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
            continue;
        if (arr[nx][ny] <= 0 || visited[nx][ny] == true)
            continue;
        dfs(nx, ny);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    year = 0;

    while (check)
    {
        year++;
        ice = 0;

        for (int i = 0; i < n; i++)
        {
            fill(visited[i], visited[i] + m, false);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] != 0)
                    melt(i, j);
                if (arr[i][j] > 0)
                    ice++;
            }
        }

        if (ice == 0)
        {
            cout << 0;
            return 0;
        }

        cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] < 0)
                    arr[i][j] = 0;

                if (arr[i][j] > 0 && visited[i][j] == false)
                {
                    dfs(i, j);
                    cnt++;
                }
            }
        }

        if (cnt >= 2)
            check = 0;
    }

    cout << year;

    return 0;
}
