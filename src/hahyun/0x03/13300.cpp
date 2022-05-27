#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, K, count = 0, arr[2][7] = {}, a, b;
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        arr[a][b] += 1;
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 1; j < 7; j++)
        {
            count += arr[i][j] / 2;
            if (arr[i][j] % 2)
                count += 1;
        }
    }
    cout << count;
}