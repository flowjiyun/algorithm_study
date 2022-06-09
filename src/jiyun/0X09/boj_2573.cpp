#include <iostream>
#include <queue>
#include <utility>

// 1.주변 0기준 녹는 맵 만들기 
// 2.빙하 맵 업데이트
// 3.빙하 갯수 확인하여 더 진행할지 판단
// 더 해야 되면 1 ~ 3 반복
using namespace std;
#define X first
#define Y second
int ice[300][300];
int melt[300][300];
int vis[300][300];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n;
int m;
void makeMelt()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (ice[i][j] <= 0)
                continue;
            int cnt = 0;
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if (ice[nx][ny] <= 0)
                    cnt++;
            }
            melt[i][j] += cnt;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            ice[i][j] -= melt[i][j];
    }
}

void bfs(int i, int j)
{
    queue<pair<int, int>> Q;
    vis[i][j] = 1;
    Q.push({i, j});
    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (vis[nx][ny] || ice[nx][ny] <= 0)
                continue;
            vis[nx][ny] = 1;
            Q.push({nx, ny}); 
        }
    }
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    // ice 만들기
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> ice[i][j];
        }
    }
    int number = 0;
    int year = 0;
    int check = 1;
    while (number < 2)
    {
        // melt 만들기
        int flag = 0;
        number = 0;
        year++;
        makeMelt();
        for (int i = 1; i < n - 1; i++)
        {
            for (int j = 1; j < m - 1; j++)
            {
                if (vis[i][j] || ice[i][j] <= 0)
                    continue;
                number++;
                bfs(i, j);                
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                vis[i][j] = 0;
                melt[i][j] = 0;
            }
        }
        for (int i = 1; i < n - 1; i++)
        {
            for (int j = 1; j < m - 1; j++)
            {
                if (ice[i][j] > 0)
                    flag = 1;
            }             
        }
        if (flag == 0)
        {
            check = 0;
            break;
        }
    }
    if (check)
        cout << year;
    else
        cout << 0; 
    return (0);
}