#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
#define X first
#define Y second
using namespace std;

string board[25];
bool vis[25][25];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n;
queue<pair<int, int>> Q;
vector<int> V;

void ft_bfs(int i, int j)
{
    vis[i][j] = true;
    Q.push({i, j});
    int area = 0;
    while(!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        area++;
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if (vis[nx][ny] || board[nx][ny] != '1')
                continue;
            vis[nx][ny] = true;
            Q.push({nx, ny});
        }
    }
    V.push_back(area);

}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> board[i];

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vis[i][j] || board[i][j] != '1')
                continue;
            cnt++;
            ft_bfs(i, j);
        }
    }
    sort(V.begin(), V.end());

    cout << cnt << '\n';
    for (auto c : V)
        cout << c << '\n';
}

