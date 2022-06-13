#include <iostream>
#include <string>
using namespace std;

int arr[129][129];
string str[129];

void fun(int x, int y, int n)
{

    for (int i = x; i < x + n; i++)
    {
        for (int j = y; j < y + n; j++)
        {
            if (arr[x][y] != arr[i][j])
            {
                cout << "(";
                fun(x, y, n / 2);
                fun(x, y + (n / 2), n / 2);
                fun(x + (n / 2), y, n / 2);
                fun(x + (n / 2), y + (n / 2), n / 2);
                cout << ")";
                return;
            }
        }
    }
    cout << arr[x][y];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            arr[i][j] = str[i][j] - '0';
    }

    fun(0, 0, n);

    return 0;
}
