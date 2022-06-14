#include <iostream>
#include <math.h>
using namespace std;

int n;
int cnt = 0;
int arr[16];

bool check(int row)
{
    for (int i = 0; i < row; i++)
    {
        if ((arr[i] == arr[row]) || (row - i == abs(arr[row] - arr[i])))
            return false;
    }
    return true;
}

void nqueen(int row)
{
    if (row == n)
    {
        cnt++;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        arr[row] = i;

        if (check(row))
            nqueen(row + 1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    nqueen(0);

    cout << cnt;

    return 0;
}
