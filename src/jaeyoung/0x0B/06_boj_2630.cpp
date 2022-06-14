#include <iostream>
using namespace std;

int board[128][128];
int res[2];
int n;

bool check(int x, int y, int size)
{
    for (int i = x; i < x + size; i++)
        for (int j = y; j < y + size; j++)
            if (board[i][j] != board[x][y])
                return false;
    return true;
}

void paper(int x, int y, int size)
{
    if (check(x, y, size))
    {
        res[board[x][y]]++;
        return;
    }

    int range = size / 2;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j <2; j++)
            paper(x + i * range, y + j * range, range);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    paper(0, 0, n);
    for (auto c : res)
        cout << c << '\n';
}