#include <iostream>
using namespace std;

char arr[3073][6145];

void star(int x, int y, int n)
{
    if (n == 3)
    {
        arr[x][y] = '*';
        arr[x + 1][y - 1] = '*';
        arr[x + 1][y + 1] = '*';
        for (int i = 0; i < 5; i++)
            arr[x + 2][y - 2 + i] = '*';
        return;
    }

    star(x, y, n / 2);
    star(x + n / 2, y - n / 2, n / 2);
    star(x + n / 2, y + n / 2, n / 2);

    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
            arr[i][j] = ' ';
    }

    star(0, n - 1, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
            cout << arr[i][j];
        cout << "\n";
    }

    return 0;
}
