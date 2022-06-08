#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#define X first
#define Y second

using namespace std;
string board[25];
int vis[25][25];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int, int>> Q;
    vector<int> ans;
    int n;
    int cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> board[i];
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] != '1' || vis[i][j] != 0)
                continue;
            vis[i][j] = 1;
            Q.push({i, j});
            cnt++;
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
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                        continue;
                    if (board[nx][ny] != '1' || vis[nx][ny] != 0)
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
        cout << ans[i] << '\n';
    return (0);
    
}