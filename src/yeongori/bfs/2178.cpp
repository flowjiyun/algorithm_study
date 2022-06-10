// 미로 탐색
#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int dist[102][102];
string board[102];
int n, m;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    // int board[100][100]을 해서 board의 원소를 각각 초기화 하는 방법도 있지만
    // string board[100]을해서 반복문을 한번만 돌 수 있다.
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> num;
    //     for (int j = m - 1; j >= 0; j--)
    //     {
    //         board[i][j] = num % 10;
    //         num /= 10;
    //     }
    // }
    for (int i = 0; i < n; i++)
        cin >> board[i];

    /*
    이 경우도 for문 2개를 사용하는 것이 아닌 어차피 인자로 포인터를 전달해야 하는
    fill함수를 사용해 2차원 배열의 초기화를 진행하는 것이 더 깔끔하다
    */
    for (int i = 0; i < n; i++)
        fill(dist[i], dist[i] + m, -1);

    queue<pair<int, int>> Q;
    Q.push({0, 0});
    dist[0][0] = 0;

    /* start bfs */
    while (!Q.empty())
    {
        // pair<int, int> 대신 auto 사용 가능
        auto cur = Q.front();
        Q.pop();
        for (int idx = 0; idx < 4; idx++)
        {
            int nx = cur.X + dx[idx];
            int ny = cur.Y + dy[idx];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            /*
            반복문 2개를 써서 int borad[102][102]를 초기화한 것이 아닌
            반복문 1개를 써 string board[102]를 초기화했으므로 비교연산 시에
            int형으로 바꿔줄 필요가 있음
            */
            if (dist[nx][ny] >= 0 || board[nx][ny] == 0 + '0')
                continue;

            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
    cout << dist[n - 1][m - 1] + 1;
}