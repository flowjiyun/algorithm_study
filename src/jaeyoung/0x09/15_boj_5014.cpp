#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;

int board[1000002];
int f, s, g, u, d;
queue<int> Q;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> f >> s >> g >> u >> d;

    fill(board + 1, board + (f + 1), -1);
    board[s] = 0;
    Q.push(s);
    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();
        for (int nx : {cur + u, cur - d})
        {
            if (nx < 1 || nx > f)
                continue;
            if (board[nx] != -1)
                continue;
            board[nx] = board[cur] + 1;
            Q.push(nx);
        }
    }
    if (board[g] != -1)
        cout << board[g];
    else
        cout << "use the stairs";
}