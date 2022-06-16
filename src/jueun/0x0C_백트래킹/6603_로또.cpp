#include <iostream>
using namespace std;

int n;
int value[14];
int arr[7];
bool visited[14];

void lotto(int k, int idx)
{
    if (k == 6)
    {
        for (int i = 0; i < 6; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";

        return;
    }

    for (int i = idx; i <= n; i++)
    {
        if (!visited[i])
        {
            arr[k] = value[i - 1];
            visited[i] = true;
            lotto(k + 1, i);
            visited[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1)
    {
        cin >> n;

        if (n == 0)
            break;

        for (int i = 0; i < n; i++)
            cin >> value[i];

        lotto(0, 1);

        cout << "\n";
    }

    return 0;
}
