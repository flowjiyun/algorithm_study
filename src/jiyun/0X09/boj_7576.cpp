#include <bits/stdc++.h>
// 시작 위치를 큐에 담아서 여러 곳에서 bfs가 일어나도록 함
// 일수를 거리로 생각할 수 있음 하루에 한칸씩 퍼져나가기 때문에
#define X first
#define Y second

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int board[1000][1000];
int day[1000][1000];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int, int>> Q;
    int n;
    int m;
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 1) // 초기 익은 토마토의 위치 큐에 저장
                Q.push({i, j});
            else if (board[i][j] == 0) // 토마토 없는 곳은 -1로 초기화
                day[i][j] = -1;
        }
    }
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
            if (day[nx][ny] != -1 || board[nx][ny] != 0)
                continue;
            day[nx][ny] = day[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            //cout << day[i][j] << ' ';
            if (day[i][j] == -1)
            {
                cout << -1;
                return (0);
            }
            if (max < day[i][j])
                max = day[i][j]; 
        }
        //cout << '\n';
    }
    cout << max;
    return (0);
}