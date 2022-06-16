#include <iostream>
#include <algorithm>
using namespace std;

int n, m, check;
int arr[9];
int value[9];

void func(int k, int idx)
{
    if (k == m)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    int check = 0;
    for (int i = idx; i <= n; i++)
    {
        if (value[i - 1] != check)
        {
            arr[k] = value[i - 1];
            check = arr[k];
            func(k + 1, i);
        }
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

    func(0, 1);

    return 0;
}
