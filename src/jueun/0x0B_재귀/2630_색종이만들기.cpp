#include <iostream>

using namespace std;

int arr[129][129];
int paper[2];

bool check(int x, int y, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[x + i][y + j] != arr[x][y])
                return false;
        }
    }

    return true;
}

void fun(int x, int y, int n)
{
    if (check(x, y, n))
    {
        paper[arr[x][y]]++;
        return;
    }

    int div = n / 2;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            fun(x + div * i, y + div * j, div);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }

    for (int i = 0; i < 2; i++)
        paper[i] = 0;

    fun(0, 0, n);

    for (int i = 0; i < 2; i++)
        cout << paper[i] << "\n";

    return 0;
}
