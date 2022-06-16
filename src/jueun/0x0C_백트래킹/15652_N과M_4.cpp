#include <iostream>
using namespace std;

int n, m;
int arr[9];

void func(int k, int idx)
{
    if (k == m)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = idx; i <= n; i++)
    {
        arr[k] = i;
        func(k + 1, i);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    func(0, 1);

    return 0;
}
