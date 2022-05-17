#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int min, cnt, n;

    min = 2147483647;
    cnt = 0;

    for (int i = 0; i < 7; i++)
    {
        cin >> n;

        if (n % 2)
        {
            if (min > n)
                min = n;
            cnt += n;
        }
    }

    if (!cnt)
        cout << -1;
    else
    {
        cout << cnt << "\n";
        cout << min;
    }
    return 0;
}