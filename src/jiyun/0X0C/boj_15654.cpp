#include <iostream>

using namespace std;
int n, m;
int ans[8];
int input[8];
int issued[8];

void s_sort(int* arr)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp; 
            }
        }
    }
}

void solve(int k)
{
    if (k == m)
    {
        for (int i = 0; i < m; i++)
            cout << ans[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (issued[i])
            continue;
        ans[k] = input[i];
        issued[i] = 1;
        solve(k + 1);
        issued[i] = 0; 
    }
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> input[i];
    s_sort(input);
    solve(0); 
    return (0);
}