#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[9];
int value[9];

void func(int k)
{
    if (k == m)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        arr[k] = value[i - 1];
        func(k + 1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }

    sort(value, value + n);

    func(0);

    return 0;
}
