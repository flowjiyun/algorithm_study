// 삽질 1. 큐에 넣는 방향 잘못 0초만에 갈수 있는 방법
// 삽질 2. 범위 지정 오류
// https://www.acmicpc.net/board/view/38887#comment-69010
#include <iostream>
#include <queue>
#include <deque>

using namespace std;

#define first
#define second
int a[3] = {2, 1, 1};
int b[3] = {0, -1, 1};

int board[200002];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    deque<int> Q;
    int n;
    int k;
    cin >> n >> k;
    for (int i = 0; i < 100001; i++)
    {
        board[i] = -1;
    }
    board[n] = 0;
    Q.push_back(n);
    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop_front();
        for (int dir = 0; dir < 3; dir++)
        {
            int nx = a[dir] * cur + b[dir];
            if (nx < 0 || nx > 100000)
                continue;
            if (board[nx] >= 0)
                continue;
            if (dir == 1 || dir == 2)
            {
                if (nx == k)
                {
                    cout << board[cur] + 1;
                    return (0);
                }
                board[nx] = board[cur] + 1;
                Q.push_back(nx);
            }
            else
            {
                if (nx == k)
                {
                    cout << board[cur];
                    return (0);
                }
                board[nx] = board[cur];
                Q.push_front(nx);
            }
        }
    }
    cout << 0;
    return (0);
}