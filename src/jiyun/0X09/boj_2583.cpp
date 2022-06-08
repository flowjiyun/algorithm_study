#include <bits/stdc++.h>
#define X first
#define Y second
int board[100][100];
int vis[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m;
    int n;
    int k;
    int cnt = 0;
    vector<int> ans;
    queue<pair<int, int>> Q;
    cin >> m >> n >> k;
    while (k--)
    {
        int x, y, xx, yy;
        cin >> x >> y >> xx >> yy;
        for (int i = 0; i < yy - y; i++)
        {
            for (int j = 0; j < xx - x; j++)
            {
                board[y + i][x + j] = 1;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 1 || vis[i][j] != 0)
                continue;
            cnt++;
            vis[i][j] = 1;
            Q.push({i, j});
            int area = 0;
            while (!Q.empty())
            {
                pair<int, int> cur = Q.front();
                Q.pop();
                area++;
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                        continue;
                    if (board[nx][ny] == 1 || vis[nx][ny] != 0)
                        continue;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
            ans.push_back(area); 
        }
    }
    sort(ans.begin(), ans.end());
    cout << cnt << '\n';
    for (int i = 0; i < cnt; i++)
        cout << ans[i] << ' ';    
    return (0);
}