#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[20];
    int n, m, cnt;

    for (int i = 0; i < 20; i++)
        arr[i] = i + 1;

    for (int i = 0; i < 10; i++)
    {
        cin >> n >> m;
        cnt = m - n + 1;

        for (int i = 0; i < cnt / 2; i++)
        {
            int tmp = arr[n - 1];
            arr[n - 1] = arr[m - 1];
            arr[m - 1] = tmp;
            n++;
            m--;
        }
    }

    for (int i = 0; i < 20; i++)
        cout << arr[i] << " ";
    return 0;
}