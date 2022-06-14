#include <iostream>
#include <algorithm>
using namespace std;

char board[2200][2200];
int N;

void print(int y, int x, int n)
{
    if (n == 1)
    {

        board[y][x] = '*';
        return;
    }
    int range = n / 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 1 && j == 1)
                continue;
            print(y +  i * range, x + j * range, range);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        fill(board[i], board[i] + N, ' ');
    print(0, 0, N);
    for (int i = 0; i < N; i++)
        cout << board[i] << '\n';
}