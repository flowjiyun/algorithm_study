#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    int s, y, cnt;

    int arr[2][7] = {0};

    cin >> n >> k;

    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> y;

        arr[s][y]++;
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 1; j < 7; j++)
        {
            if (arr[i][j] <= k && arr[i][j])
                cnt++;
            else
            {
                if (arr[i][j] % k)
                    cnt += arr[i][j] / k + 1;
                else
                    cnt += arr[i][j] / k;
            }
        }
    }

    cout << cnt;

    return 0;
}