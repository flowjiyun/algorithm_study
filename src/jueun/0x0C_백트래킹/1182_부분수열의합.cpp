#include <iostream>
using namespace std;

int n, s;
int cnt = 0;
int arr[21];

void func(int k, int sum)
{
    if (n == k)
    {
        if (s == sum)
            cnt++;
        return;
    }

    func(k + 1, sum);
    func(k + 1, sum + arr[k]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    func(0, 0);

    if (s == 0)
        cnt--;

    cout << cnt;

    return 0;
}
