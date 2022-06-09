#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int board[200][200];
int dist[200][200][30];
int dx[12] = {1, 0, -1, 0, 2, 2, 1, 1, -1, -1, -2, -2};
int dy[12] = {0, 1, 0, -1, 1, -1, 2, -2, 2, -2, 1, -1};
int K, W, H;
queue<tuple<int, int, int>> Q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> K >> W >> H; // W는 열, H는 행

    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            cin >> board[i][j];
    
    Q.push({0, 0, K});
    dist[0][0][0] = 1;
    while (!Q.empty())
    {
        tuple<int, int, int> cur = Q.front();
        Q.pop();
        int cur_X, cur_Y, jump;
        tie(cur_X, cur_Y, jump) = cur;
        if (cur_X == H - 1 && cur_Y == W - 1)
        {
            cout << dist[cur_X][cur_Y][jump];
            return (0);
        }
        for (int dir = 0; dir < 12; dir++)
        {
            int nx = cur_X + dx[dir];
            int ny = cur_Y + dy[dir];

            if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                continue;
            if (dir >= 4)
            {
                if (jump == 0)
                    continue;
                if (dist[nx][ny][jump - 1] == 0 && board[nx][ny] == 0)
                {
                    dist[nx][ny][jump - 1] = dist[cur_X][cur_Y][jump] + 1;
                    Q.push({nx, ny, jump - 1});
                }
            }
            else
            {
                if (dist[nx][ny][jump] == 0 && board[nx][ny] == 0)
                {
                    dist[nx][ny][jump] = dist[cur_X][cur_Y][jump] + 1;
                    Q.push({nx, ny, jump});
                }
            }
        }
    }
    cout << -1;
}