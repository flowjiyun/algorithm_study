#include <iostream>
using namespace std;

int n;
int board[2200][2200];
int res[3]; // [0] = -1, [1] = 0, [2] = 1;

bool check(int x, int y, int size)
{
    for (int i = x; i < x + size; i++)
    {
        for (int j = y; j < y + size; j++)
            {
                if (board[i][j] != board[x][y])
                    return false;
            }
    }
    return true;
            
}

void paper(int x, int y, int size)
{
    if (check(x, y, size))
    {
        res[board[x][y] + 1]++;
        return;
    }

    int range = size / 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
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