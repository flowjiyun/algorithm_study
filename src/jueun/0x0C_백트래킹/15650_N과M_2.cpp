#include <iostream>
using namespace std;

int n, m;
int arr[9];
bool visited[9];

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
        if (!visited[i])
        {
            arr[k] = i;
            visited[i] = true;
            func(k + 1, i);
            visited[i] = false;
        }
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
