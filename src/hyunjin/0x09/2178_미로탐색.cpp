#include <iostream>
#include <queue>
using namespace std;
#define Y first
#define X second

int board[105][105];
int used[105][105];

int main()
{
    int n, m;
    cin >> n >> m;
    string str;
    for (int y = 0; y < n; y++) {
        cin >> str;
        for (int x = 0; x < m; x++) {
            board[y][x] = str[x] - '0';
        }
    }

    int dy[4] = { -1, 0, 0, 1 };
    int dx[4] = { 0, -1, 1, 0 };

    queue<pair<int, int>> q;
    int cnt = 1;
    q.push({ 0, 0 });
    used[0][0] = cnt++;

    pair<int, int> cur;
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cur.Y + dy[i];
            int nx = cur.X + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (board[ny][nx] == 0 || used[ny][nx] > 0) continue;

            used[ny][nx] = used[cur.Y][cur.X] + 1;
            q.push({ ny, nx });
        }
    }
    cout << used[n - 1][m - 1];
}

