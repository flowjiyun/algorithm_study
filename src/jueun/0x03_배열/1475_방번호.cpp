#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, cnt;
    vector<int> v(10);

    cin >> n;

    while (n > 0)
    {
        v[n % 10]++;
        n = n / 10;
    }

    cnt = 0;

    if (!(v[6] <= 1 && v[9] <= 1))
    {
        v[6] = (v[6] + v[9] + 1) / 2;
        v[9] = 0;
    }

    for (int i = 0; i < 10; i++)
    {
        if (v[i] > cnt)
            cnt = v[i];
    }

    cout << cnt;

    return 0;
}